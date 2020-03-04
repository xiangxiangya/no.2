#include"creat.h"
#include<string.h>
int main()
{
    int chmid=CreateMem();
    char *p=(char*)shmat(chmid,NULL,0);
    strcpy(p,"hello!");
    return 0;
}
