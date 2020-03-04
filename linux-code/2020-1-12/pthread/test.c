#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *PthreadEnter(void *arg){
    int *count=(int *)arg;
    while(1){
        ++*count;
        printf("in PthreadEnter\n");
        sleep(1);
    }

}

int main()
{
    int count=0;
    pthread_t tid;
    pthread_create(&tid,NULL,PthreadEnter,&count);
    while(1){
        printf("in mainthread,%d\n",count);
        sleep(1);
    }
        
    return 0;
}
