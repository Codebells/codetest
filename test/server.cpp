#include <zmq.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <proto/message.pb.h>
#include "utils.h"
using namespace std;

int main(int argc, char *argv)
{
    std::unique_ptr<std::string> message_string_ptr;
    std::unique_ptr<proto::Message> msg_ptr;
    std::unique_ptr<proto::Transaction> txn_ptr;
    std::string csn_temp, key_temp, key_str, table_name, csn_result;

    zmq::context_t listen_context(1);
    zmq::socket_t socket_listen(listen_context, ZMQ_SUB);
    int queue_length = 0;
    getIp();
    socket_listen.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    socket_listen.connect("tcp://" + selfIpAddress + ":5551");
    while (1)
    {
        std::unique_ptr<zmq::message_t> message_ptr = std::make_unique<zmq::message_t>();
        socket_listen.recv(&(*message_ptr)); // 防止上次遗留消息造成message cache出现问题
        message_string_ptr = std::make_unique<std::string>(static_cast<const char *>(message_ptr->data()), message_ptr->size());
        msg_ptr = std::make_unique<proto::Message>();
        auto res = UnGzip(msg_ptr.get(), message_string_ptr.get());
        assert(res);
        if (msg_ptr->type_case() == proto::Message::TypeCase::kTxn)
        {
            txn_ptr = make_unique<proto::Transaction>(*(msg_ptr->release_txn()));
            if (txn_ptr->txn_type() == proto::TxnType::ClientTxn)
            { /// sql node --> txn node
                /// local 来自sql node的事务，local_txn_queue 进行第一次预处理。 处理完成后会放入first_merged_queue，再有cache thread进行缓存
                printf("txn worker receive a client request - 1\n");
                txn_ptr->set_commit_epoch(EpochManager::GetPhysicalEpoch());
                EpochManager::local_should_exec_txn_num.IncCount(txn_ptr->commit_epoch(), id, 1);
                txn_ptr->set_csn(now_to_us());
                txn_ptr->set_server_id(local_ip_index);
                local_txn_queue.enqueue(std::move(txn_ptr));
                printf("txn receive a client commit request - 2\n");
                for(auto i = 0; i < txn.row_size(); i ++){
                    const auto& row = txn.row(i);
                    if(row.op_type() == proto::OpType::Read){
                        printf("%s \n",row.key());
                    }
                    else{
                        printf("%s %s\n",row.key(),row.value());
                    }
                }
            }
        }
    }
}