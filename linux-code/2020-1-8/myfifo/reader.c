#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd=open("./myfifo",O_RDONLY);
    while(1)
    {
    char buf[1024]={0};
        int ret=read(fd,buf,sizeof(buf)-1);
        if(ret<0){
            perror("raed");
        }
        if(ret==0){
        }
        else{
            printf("%s\n",buf);
        }

    }
}
