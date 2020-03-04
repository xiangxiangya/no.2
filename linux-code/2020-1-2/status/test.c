#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid=fork();
    if(pid==0){
        //child
        int count=3;
        while(count){
            printf("child %d\n",getpid());
            sleep(1);
            count--;
        }
        exit(3);
    }
    else if(pid>0){
        //father
        int status=0;
        printf("father %d\n",getpid());
        int ret=wait(&status);//status是出参
        printf("ret(wait 的返回值) %d\n",ret);
        if(status & 0xff){
            //低八位不为0，说明是异常退出
            printf("%d\n",status&0x7f);
        }
        else{
            //低八位为0，说明是正常退出
            printf("%d\n",(status>>8)&0xff);
        }
    }
    return 0;
}
