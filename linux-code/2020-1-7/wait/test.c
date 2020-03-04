#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

#include<stdlib.h>

int main()
{
    int pid=fork();
    if(pid==0){
        sleep(3);
        exit(0);
    }
    else if(pid>0){
    }
    int pid2=fork();
    if(pid2==0){
        sleep(4);
        exit(0);
    }
    else if(pid2>0){
    }
    //wait(NULL);
    //wait(NULL);
    waitpid(pid,NULL,WNOHANG);

    while(1){}
    return 0;
}
