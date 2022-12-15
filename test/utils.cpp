//
// Created by 周慰星 on 2022/10/24.
//
#include <zmq.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <proto/message.pb.h>
#include "utils.h"
void getIp(){
    ifstream infile; 
    infile.open("ip.txt"); 
    infile>>destIpAddress;
    infile>>selfIpAddress;
    infile.close();
}
void setTxnType(proto::Row* row, OperationType &&opType){
    switch (opType)
    {
    case OperationType::kRead :
        row->set_op_type(proto::OpType::Read);
        break;
    case OperationType::kInsert :
        row->set_op_type(proto::OpType::Insert);
        break;
    case OperationType::kUpdate :
        row->set_op_type(proto::OpType::Update);
        break;
    case OperationType::kDelete :
        row->set_op_type(proto::OpType::Delete);
        break;
    default:
        break;
    }
}
void PromptForColumn(proto::Column* col , std::string value = ""){
    col->set_id(1);
    col->set_value(value);
}
void PromptForRow(proto::Row* row ,KV &kv, OperationType &&opType){
    setTxnType(row , move(opType));
    row->set_table_name("table1");
    std::string key =kv.first;
    std::string data =kv.second;
    row->set_key(key);
    row->set_data(data);
    PromptForColumn(row->add_column(), kv.second);
}
void PromptForRow(proto::Row* row ,std::string &key, OperationType &&opType){
    setTxnType(row , move(opType));
    row->set_table_name("table1");
    row->set_key(key);
    row->set_data("not_put");
    PromptForColumn(row->add_column());
}

proto::TxnState sendMessage(std::vector<KV> &kv , OperationType &&opType){ //put
    auto msg =  std::make_unique<proto::Message>();
    auto apply = msg->mutable_txn();
    for(auto p : kv){
        PromptForRow(apply->add_row(), p, move(opType));
    }
    apply->set_start_epoch(1);
    apply->set_client_ip(selfIpAddress);
    apply->set_client_txn_id(5);
    apply->set_txn_type(proto::TxnType::ClientTxn);

    auto serialized_txn_str_ptr = std::make_unique<std::string>();
    auto res = Gzip(msg.get(), serialized_txn_str_ptr.get());
    assert(res);
    zmq::context_t context(1);
    zmq::socket_t socket_send(context, ZMQ_PUB);
    socket_send.bind("tcp://"+destIpAddress+":5551");
    std::unique_ptr<zmq::message_t> message_ptr = std::make_unique<zmq::message_t>(*(serialized_txn_str_ptr));
    socket_send.send(*(message_ptr));

    bool isReceived = false;
    std::unique_ptr<zmq::message_t> recv;
    std::unique_ptr<std::string> recv_message_string_ptr;
    std::unique_ptr<proto::Message> recv_msg_ptr;
    std::unique_ptr<proto::ReplyTransactionToClient> reply_txn;
    while(!isReceived){
        recv = std::make_unique<zmq::message_t>();
        socket_send.recv(&(*recv));
        recv_message_string_ptr = std::make_unique<std::string>(static_cast<const char*>(recv->data()), recv->size());
        recv_msg_ptr = std::make_unique<proto::Message>();
        auto res = UnGzip(recv_msg_ptr.get(), recv_message_string_ptr.get());
        assert(res);
        if(recv_msg_ptr->type_case() == proto::Message::TypeCase::kReplyTxnResultToClient){
            reply_txn = make_unique<proto::ReplyTransactionToClient>(*(recv_msg_ptr->release_reply_txn_result_to_client()));
            break;
        }
    }
    // if(reply_txn->txn_state() == proto::TxnState::Commit){

    // }else if(reply_txn->txn_state() == proto::TxnState::Abort){

    // }
    Send_ok(kv);
    return reply_txn->txn_state();
}
proto::TxnState sendMessage(std::vector<std::string> &Keys, OperationType &&opType){ //get or remove
    auto msg =  std::make_unique<proto::Message>();
    auto apply = msg->mutable_txn();
    for(auto k : Keys){
        PromptForRow(apply->add_row(), k, move(opType));
    }
    apply->set_start_epoch(1);
    apply->set_client_ip(selfIpAddress);
    apply->set_client_txn_id(5);
    apply->set_txn_type(proto::TxnType::ClientTxn);

    auto serialized_txn_str_ptr = std::make_unique<std::string>();
    auto res = Gzip(msg.get(), serialized_txn_str_ptr.get());
    assert(res);
    zmq::context_t context(1);
    zmq::socket_t socket_send(context, ZMQ_PUB);
    // socket_send.bind("tcp://"+destIpAddress+":5551");
    socket_send.bind("tcp://*:5551");
    std::unique_ptr<zmq::message_t> message_ptr = std::make_unique<zmq::message_t>(*(serialized_txn_str_ptr));
    socket_send.send(*(message_ptr));

    bool isReceived = false;
    std::unique_ptr<zmq::message_t> recv;
    std::unique_ptr<std::string> recv_message_string_ptr;
    std::unique_ptr<proto::Message> recv_msg_ptr;
    std::unique_ptr<proto::ReplyTransactionToClient> reply_txn;
    while(!isReceived){
        recv = std::make_unique<zmq::message_t>();
        socket_send.recv(&(*recv));
        recv_message_string_ptr = std::make_unique<std::string>(static_cast<const char*>(recv->data()), recv->size());
        recv_msg_ptr = std::make_unique<proto::Message>();
        auto res = UnGzip(recv_msg_ptr.get(), recv_message_string_ptr.get());
        assert(res);
        if(recv_msg_ptr->type_case() == proto::Message::TypeCase::kReplyTxnResultToClient){
            reply_txn = make_unique<proto::ReplyTransactionToClient>(*(recv_msg_ptr->release_reply_txn_result_to_client()));
            break;
        }
    }
    return reply_txn->txn_state();
}
// bool sendMessage(){
//     auto msg =  std::make_unique<proto::Message>();
//     auto apply = msg->mutable_txn();
//     // PromptForRow(apply->add_row());//add row
//     apply->set_start_epoch(1);
//     apply->set_client_ip("127.0.0.1");
//     apply->set_client_txn_id(5);
    
//     apply->set_commit_epoch(2);
//     apply->set_csn(3);
//     apply->set_server_ip("127.0.0.1");
//     apply->set_server_id(4);
//     apply->set_txn_type(proto::TxnType::ClientTxn);
//     apply->set_txn_state(proto::TxnState::Commit);
//     // 将Transaction使用protobuf进行序列化，序列化的结果在serialized_txn_str_ptr中
//     auto serialized_txn_str_ptr = std::make_unique<std::string>();
//     auto res = Gzip(msg.get(), serialized_txn_str_ptr.get());
//     assert(res);
//     zmq::context_t context(1);
//     zmq::socket_t socket_send(context, ZMQ_PUB);
//     socket_send.bind("tcp://*:5551");
//     std::unique_ptr<zmq::message_t> message_ptr = std::make_unique<zmq::message_t>(*(serialized_txn_str_ptr));
//     socket_send.send(*(message_ptr));
// }

void Send_ok(std::vector<KV> &kv){
    ofstream outfile;
    outfile.open("out.txt");
    for(auto it : kv){
        outfile<<it.first<<"-----"<<it.second<<endl;
    }
    outfile<<"------------------------------------"<<endl;
    outfile.close();
}

bool Gzip(google::protobuf::MessageLite* ptr, std::string* serialized_str_ptr) {
    google::protobuf::io::GzipOutputStream::Options options;
    options.format = google::protobuf::io::GzipOutputStream::GZIP;
    options.compression_level = 9;
    google::protobuf::io::StringOutputStream outputStream(serialized_str_ptr);
    google::protobuf::io::GzipOutputStream gzipStream(&outputStream, options);
    ptr->SerializeToZeroCopyStream(&gzipStream);
    gzipStream.Close();
    return true;
}

bool UnGzip(google::protobuf::MessageLite* ptr, const std::string* str) {
//    auto message_string_ptr = std::make_unique<std::string>(static_cast<const char*>(message_ptr->data()), message_ptr->size());
    google::protobuf::io::ArrayInputStream inputStream(str->data(), (int)str->size());
    google::protobuf::io::GzipInputStream gzipStream(&inputStream);
    ptr->ParseFromZeroCopyStream(&gzipStream);
    return true;
}