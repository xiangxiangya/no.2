#include"server.hpp"

void Echo(const std::string &req,std::string *resp)
{
    *resp=req;//把响应设成请求
}

int main()
{
    UdpServer server;
    while(1)
    {
    server.Start("0.0.0.0",9090,Echo);

    }
    return 0;
}
