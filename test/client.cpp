#include <zmq.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <proto/message.pb.h>
#include "utils.h"
int main(int argc,char *argv){
    std::vector<KV> put ;
    std::vector<std::string> get;
    int num = 0;
    int p;
    while(std::cin>>p)
    {
        for(int i = num ;i < num+10 ; i++)
        {
            std::string key = "putkey";
            std::string key2 = "getkey";
            std::string value = "value";
            std::string tmp;
            sprintf(tmp,"%d",i);
            key.append(tmp);
            key2.append(tmp);
            value.append(tmp);
            put.push_back(make_pair(key,value));
            get.push_back(key2);
        }
        sendMessage(put,OperationType::kInsert);
        sendMessage(get,OperationType::kRead);
    }
}