#include<stdio.h>
#include <unistd.h>

int main()
{
    int i=0;
    int pid=fork();
    if(pid==0){
        printf("%d\n",i);
        printf("child\n");
    }
    if(pid>0){
        printf("father\n");
    }

    return 0;
}
