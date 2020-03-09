#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#if 0
#define THREAD_NUM 2

int g_count=0;

pthread_mutex_t mutex;//定义全局变量，互斥量

void *ThreadEnter(void *arg){
    (void)arg;
    int i=0;
    for(i=0;i<50000;++i){
        pthread_mutex_lock(&mutex);//在临界区之前上锁
        g_count++;
        pthread_mutex_unlock(&mutex);//在临界区之后解锁
    }
    return NULL;
}

int main()
{
    int i=0;
    pthread_mutex_init(&mutex,NULL);//对这个互斥量初始化
    pthread_t tid[THREAD_NUM];
    for(i=0;i<THREAD_NUM;++i){
        pthread_create(&tid[i],NULL,ThreadEnter,NULL);
    }
    for(i=0;i<THREAD_NUM;++i){
        pthread_join(tid[i],NULL);
    }
    printf("%d\n",g_count);
    pthread_mutex_destroy(&mutex);//释放这个互斥量
    return 0;
}
#endif


pthread_mutex_t mutex;//定义全局变量，互斥量
pthread_cond_t cond;//定义全局变量，同步变量

void* ThreadEnter1(void *arg)
{
    (void)arg;
    while(1)
    {
        pthread_cond_signal(&cond);
        printf("传球\n");
        usleep(879789);
    }
    return NULL;
}

void* ThreadEnter2(void * arg)
{
    (void)arg;
    while(1)
    {
        pthread_cond_wait(&cond,&mutex);//让快的线程等待，等到慢的发出信号结束阻塞
        printf("扣篮\n");
        usleep(211234);
    }
    return NULL;
}
int main()
{
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,ThreadEnter1,NULL);
    pthread_create(&tid2,NULL,ThreadEnter2,NULL);
    pthread_join(tid1,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_join(tid2,NULL);
    return 0;
}
