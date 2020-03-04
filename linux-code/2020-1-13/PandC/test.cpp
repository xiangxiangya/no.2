#include<stdio.h>
#include<iostream>
#include<vector>
#include<pthread.h>
#include<unistd.h>

//仓库
std::vector<int> data; 

//定义互斥量,互斥使消费者和生产者之间实现互斥关系
pthread_mutex_t mutex;


//定义条件变量，使消费者在vector有数据时才消费，没有数据时啥都不做
//提高代码效率
pthread_cond_t cond;

//还需要生产者和消费者->线程
void * Product(void *arg)
{
    (void)arg;
    int count=0;
    //生产者负责往vector中写数据
    while(1)
    {
        pthread_mutex_lock(&mutex);
        data.push_back(++count);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        usleep(898778);
    }
    return NULL;
}
void * Consume(void *arg)
{
    (void)arg;
    //消费者负责读数据
    while(1){
        pthread_mutex_lock(&mutex);
        while(data.empty()){
            //如果当前的vector是空的，消费者没有必要去一直读取其中的数据
            //所以让消费者线程进行等待，不必进行空转也就节省了资源
            pthread_cond_wait(&cond,&mutex);
            //此函数的执行
            //1.释放锁
            //2.等待其他线程pthread_cond_signal()函数返回
            //3.重新获取锁
        }
        std::cout<<"result:"<<data.back()<<std::endl;
        data.pop_back();
        pthread_mutex_unlock(&mutex);
        usleep(124242);//让消费者执行速度快
    }
    return NULL;
}


int main()
{
    pthread_t tid1,tid2,tid3,tid4;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    //创建线程
    pthread_create(&tid1,NULL,Product,NULL);
    pthread_create(&tid3,NULL,Product,NULL);
    pthread_create(&tid2,NULL,Consume,NULL);
    pthread_create(&tid4,NULL,Consume,NULL);
    //线程等待
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
