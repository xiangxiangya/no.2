#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    fclose(stdout);//这里将标准输出关闭只会对当前文件造成影响，在另一个文件中想要打印的信息依然会正常打印
    int fd;
    fd=open("hello.txt",O_CREAT);
    printf("jeje");
    printf("%d",fd);
    return 0;
}
