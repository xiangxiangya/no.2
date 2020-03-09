#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int _main()
{
    int i=0;
    //若没有刷新缓冲区printf并没有显示在控制台上而是在缓冲区，经过fork后会继承到所fork出
    //的子进程中，再printf时就会有8个=显示
    //若是刷新缓冲区则先将第一次循环的=打印在缓冲区上，然后再写入4个=即最终会打印6个等号
    for(i=0;i<2;++i){
        fork();
        printf("=");
        fflush(stdout);
    }
    return 0;
}

int Fun(int a)
{
    printf("%d\n",a);
}

int main(int argc,char * argv[],char * env[])
{
    (void) argc;//消除警告
    sleep(100);
    int i=0;
   // printf("%d\n",argc);
   // for ( i=0;i<argc;++i){
   //     printf("%s\n",argv[i]);
   // }
    //for(i=0;env[i]!=NULL;++i){
    //    printf("%s\n",env[i]);
    int result=0;
    int ret=fork();
    if(ret==0){
        int count=4;
        while(count>0){
            printf("child %d\n",getpid());
            sleep(1);
            count--;
        }
        exit(5);
    }else if(ret>0){
        int staus=0;
        printf("father %d\n",getpid());
        result=wait(&staus);
        printf("staus %d\n",staus);
        printf("result %d\n",result);
    }
    return 0;
}
