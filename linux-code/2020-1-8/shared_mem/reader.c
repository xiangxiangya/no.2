#include"creat.h"
int main()
{
    int shmid=CreateMem();//创建/打开一个共享内存
    char *p=(char*)shmat(shmid,NULL,0);//依附到共享内存空间
    printf("%s\n",p);
    return 0;
}
