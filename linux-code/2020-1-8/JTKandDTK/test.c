#include<stdio.h>

extern int Add(int x,int y);

int main()
{
    int ret=Add(10,20);
    printf("%d\n",ret);
    return 0;
}
