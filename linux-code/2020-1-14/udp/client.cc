#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>
int main(int argc,char * argv[])
{
    (void)argc;
    int sock=socket(AF_INET,SOCK_DGRAM,0);
    if(sock<0){
        perror("socket");
    }

    sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(argv[1]);
    server.sin_port=htons(9090);
    socklen_t len=sizeof(server);
    while(1)
    {
        char buf[1024]={0};
        printf("请输入->");
        fflush(stdout);
        scanf("%s",buf);
        sendto(sock,buf,strlen(buf),0,(sockaddr*)&server,sizeof(server));
        char _out[1024]={0};
        recvfrom(sock,_out,sizeof(_out),0,(sockaddr*)&server,&len);
        printf("server resp %s\n",_out);
    }
    return 0;
}
