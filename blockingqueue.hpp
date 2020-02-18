#pragma once
#include<vector>
#include<pthread.h>
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<semaphore.h>

//用信号量模拟实现阻塞队列的生产消费模型
//阻塞队列的长度一般是有上限的
//如果队列为空pop就会阻塞
//如果队列为满，push就会阻塞
 
//信号量表示可用资源的个数
//用一个来表示队列中元素的个数
//用另一个来表示队列中空格的个数

template<class T>
class BlockingQueue
{
    public:
        BlockingQueue(int max_size)
            :_max_size(max_size)
             ,_head(0)
             ,_tail(0)
             ,_size(0)
             ,_queue(max_size)
        {
            sem_init(&_lock,0,1);
            sem_init(&_elem,0,0);//元素个数为0
            sem_init(&_block,0,_max_size);//空格个数为队列大小
        }
        void push(const T &data){
           //Push操作要申请一个空格资源
           //如果没有空格资源就会陷入阻塞
            sem_wait(&_block);

            sem_wait(&_lock);//申请资源，对信号量进行P操作
            _queue[_tail]=data;
            _tail++;
            _size++;
            sem_post(&_lock);//释放资源，对信号量进行V操作

            //Push结束后要释放一个元素资源
            sem_post(&_elem);
        }

        //data是出队列的元素，
        //指针表示输出型参数，引用表示出入型参数，const类型的引用表示输入参数
        void pop(T*data){
            //Pop操作先申请一个元素资源
            //如果队列中没有元素就陷入阻塞
            sem_wait(&_elem);
            sem_wait(&_lock);
            *data=_queue[_head];
            _head++;
            _size--;
            sem_post(&_lock);

            //Pop结束后要释放一个空格资源
            sem_post(&_block);
        }

        ~BlockingQueue()
        {
            sem_close(&_lock);
            sem_close(&_elem);
            sem_close(&_block);
        }
    private:
        int _max_size;
        int _head;
        int _tail;
        int _size;
        std::vector<T> _queue;
        sem_t _lock;//用一个二元信号量表示互斥锁
        sem_t _elem;
        sem_t _block;
};
