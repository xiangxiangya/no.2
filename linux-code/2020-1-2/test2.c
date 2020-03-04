#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid=0;
    pid=fork();
    if(pid==0){

        sleep(100);
    }
    else if(pid>0){
    }
    return 0;
}
