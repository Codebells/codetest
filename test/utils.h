//
// Created by 周慰星 on 2022/10/24.
//

#ifndef TAAS_UTILS_H
#define TAAS_UTILS_H
#include <stdlib.h>
#include <iostream>
#include "proto/message.pb.h"
#include <google/protobuf/io/gzip_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

using namespace std;
#define UNUSED_VALUE(v) (void)(v);
using KV = std::pair<std::string, std::string>;
std::string selfIpAddress,destIpAddress;
enum class OperationType : uint32_t {
  kRead = 0x00000001,
  kInsert = 0x00000002,
  kUpdate = 0x00000003,
  kDelete = 0x00000004,
};
// template <typename T>
// unique_ptr<string> Gzip(unique_ptr<T>&& ptr);

// template <typename T> // ptr is origin return-value
// void UnGzip(unique_ptr<T>& ptr, unique_ptr<string>&& str);


bool Gzip(google::protobuf::MessageLite* ptr, std::string* serialized_str_ptr);

bool UnGzip(google::protobuf::MessageLite* ptr, const std::string* str);

void Send_ok(std::vector<KV> &kv);

void getIp();
void setTxnType(proto::Row* row, OperationType &&opType);
void PromptForColumn(proto::Column* col , std::string value = "");
void PromptForRow(proto::Row* row ,KV &kv, OperationType &&opType);
void PromptForRow(proto::Row* row ,std::string &key, OperationType &&opType);
proto::TxnState sendMessage(std::vector<KV> &kv , OperationType &&opType);
proto::TxnState sendMessage(std::vector<std::string> &Keys, OperationType &&opType);

#endif //TAAS_UTILS_H
