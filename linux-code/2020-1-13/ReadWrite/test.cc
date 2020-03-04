#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//1.交易场所
int count=0;

//2.两种角色




int main()
{
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,Reader,NULL);
    pthread_create(&tid2,NULL,Writer,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}
