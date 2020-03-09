#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd=open("./myfifo",O_WRONLY);
    char buf[1024]={0};
    while(1)
    {
        printf("->");
        gets(buf);
        write(fd,buf,sizeof(buf)-1);
    }
    return 0;
}
