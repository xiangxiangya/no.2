#include<stdio.h>
#include<unistd.h>

int main()
{
    execl("/usr/bin/ls","ls",NULL);
    execl("./test1","test1",NULL);  //可以正常运行test1中的内容
    execlp("test1","test1",NULL);//将当前路径添加到环境变量中后就可直接使用
    return 0;
}
