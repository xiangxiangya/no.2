#pragma once
#include<cassert>
#include<functional>
#include"udp_socket.hpp"

//通用的Udp服务器
//服务器三步
//1.读取请求
//2.根据响应计算请求
//3.把响应协会客户端
//其中1、3使固定套路，任何场景都一样
//2是和业务相关。所以就把2对应的代码提取成一个回调函数

//typedef void (*Handler)(const std::string &req,std::string *resp);//函数指针

typedef std::function<void(const std::string&,std::string*)> Handler;

class UdpServer
{
    public:
        UdpServer()
        {
            assert(sock_.Socket());
        }

        ~UdpServer()
        {
            sock_.Close();
        }

        bool Start(const std::string &ip,uint16_t port,Handler handler)
        {
            //1.创建socket(已完成)
            //2.绑定端口号
            bool ret = sock_.Bind(ip,port);
            if(!ret){
                return false;
            }
            //3.进入死循环
            while(true)
            {
                std::string req;
                std::string peer_ip;
                uint16_t peer_port;
                sock_.RecvFrom(&req,&peer_ip,&peer_port);
                std::string resp;
                handler(req,&resp);
                sock_.SendTo(resp,peer_ip,peer_port);
            }
        }
    private:
        UdpSocket sock_;
        
};
