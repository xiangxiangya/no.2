#pragma once
#include"tcp_socket.hpp"
#include<functional>

#define CHECK_RET(exp) if(!(exp)){return false;}

typedef std::function<void(const std::string &,std::string *)> Handler;

class TcpServer
{
    public:
        TcpServer()
        {


        }
        bool Start(const std::string &ip,uint_fast16_t port,Handler handler)
        {
           //1.创建一个socket
           CHECK_RET(listen_sock_.Socket());
           //2.绑定端口号和ip
          CHECK_RET(listen_sock_.Bind(ip,port));
           //3.进行监听
           CHECK_RET(listen_sock_.Listen());
           printf("server start ok!\n");
           //4.进入主循环
           while(true){
               //5.获取到连接
               TcpSocket client_sock;
               std::string ip;
                uint16_t port;
               bool ret=listen_sock_.Accept(&client_sock,&ip,&port);
               if(!ret){
                   continue;
               }
               //6.和客户端进行具体的沟通
               while(true){
                   std::string req;
                   client_sock.Recv(&req)
               }
           }
        }
    private:
        TcpSocket listen_sock_;
};
