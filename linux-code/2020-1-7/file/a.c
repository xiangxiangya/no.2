#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    //printf("%d\n",stdout->_fileno);
    int fd=open("1.c",O_RDWR);
   dup2(fd,1); 
    return 0;
}
