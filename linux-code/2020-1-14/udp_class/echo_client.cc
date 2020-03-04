#include"client.hpp"
#include<iostream>
int main()
{
    UdpClient client("0.0.0.0",9090);
    while(1)
    {
        std::string buf;
        std::cin>>buf;
        client.SendTo(buf);
        std::string res;
        client.RecvFrom(&res);
        std::cout<<res;
    }
    return 0;
}
