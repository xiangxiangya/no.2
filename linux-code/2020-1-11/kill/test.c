#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
//m模拟实现系统的kill命令
int main(int argc,char *argv[])
{
    //只实现处理一个进程的情况
    if(argc!=3){
        printf("参数有误\n");
        return 1;
    }
    pid_t pid=atoi(argv[2]);
    int signo=atoi(argv[1]+1);
    int ret=kill(pid,signo);
    if(ret<0){
        perror("kill");
        return 1;
    }
    printf("%d\n",signo);
    return 0;
}
