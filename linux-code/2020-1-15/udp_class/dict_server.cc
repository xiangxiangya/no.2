//创建一个中英文翻译的服务器
#include"server.hpp"
#include<unordered_map>

int main()
{
    std::unordered_map<std::string ,std::string> dict;                                                                    
    dict.insert(std::make_pair("hello","你好"));  
    dict.insert(std::make_pair("world","世界"));  
    dict.insert(std::make_pair("bit","比特"));  
    UdpServer server;
    server.Start("0.0.0.0",9090,[&dict](const std::string &req,std::string *resp){
            std::unordered_map<std::string ,std::string> dict;
            dict.insert(std::make_pair("hello","你好"));
            dict.insert(std::make_pair("world","世界"));
            dict.insert(std::make_pair("bit","比特"));
            auto it = dict.find(req);
            if(it==dict.end()){
            *resp="未找到\n";
            }else{
            *resp=it->second;
            }
            });
    return 0;
}
