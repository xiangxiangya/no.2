#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    //printf("%d\n",stdout->_fileno);
    int fd=open("a.c",O_RDWR);
    dup2(fd,1); 
    return 0;
}
