#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd=open("a.txt",O_CREAT|O_RDWR,0777);
    printf("%d",fd);
    return 0;
}
