#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>
//UDP版本的服务器
int main()
{
    //AF_INET表示使用ipv4协议
    //SOCK_DGRAM表示使用UDP协议
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    if(sock<0){
        perror("socket");
        return 1;
    }

    //设置addr这个结构体
    //1.协议族
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    //2.IP地址也是一个整数也需要转为网络字节序，inet_addr已经自动完成了
    addr.sin_addr.s_addr=inet_addr("0.0.0.0");//代表所有的IP地址
    //3.端口号先转为网络字节序
    addr.sin_port =htons(9090);
    int ret=bind(sock,(sockaddr *)&addr,sizeof(addr));
    if(ret<0){
        perror("bind");
        return 1;
    }
    printf("server start ok\n");
    while(true){
        //UDP专用
        sockaddr_in peer;//输出型参数,这个结构体代表的是客户端的信息
        socklen_t len=sizeof(peer);//是一个整数，描述peer结构体的长度
        //是一个输入输出参数,由于是通用类型的所以要告诉操作系统这个结构体具体的长度，就会知道是什么类型
        //1.接受请求
        char buf[1024]={0};
        ssize_t n=recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr *)&peer,&len);
        if(n<0){
            perror("recvfrom");
            continue;
        }
        //2.根据请求计算响应
        //由于是回显服务器所以省略这步
        //3.将响应写回客户端
        n=sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
        if(n<0){
            perror("sendto");
            continue;
        }
        printf("[%s:%d] buf =%s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
    }
    close(sock);
    return 0;
}
