#pragma once
#include"blockingqueue.hpp"

class Task
{
    public:
        virtual ~Task()
        {}
        virtual void Run()
        {
            printf("base\n");
        }
};


//线程池对象是用来干嘛的？
//它启动的时候创建一组线程并去完成特定的任务(去执行一定的代码逻辑)
//这个逻辑是由调用者来决定
class Threadpool
{
    public:
        //n代表创建的线程个数
        Threadpool(int n)
            :_queue(100)
             ,_worker_count(n)//设定阻塞队列的起始大小
        {
            //创建出n个线程
            int i=0;
            for(i=0;i<_worker_count;++i){
                //创建线程
                pthread_t tid;
                //由于在启动函数中要对类的成员进行操作，所以第四个参数传this指针
                pthread_create(&tid,NULL,ThreadEnter,this);
                _workers.push_back(tid);
            }
        }
        ~Threadpool()
        {
            size_t i=0;
            //先让线程退出再回收
            for(i=0;i<_workers.size();++i){
                pthread_cancel(_workers[i]);
            }
            for(i=0;i<_workers.size();++i){
               pthread_join(_workers[i],NULL); 
            }
        }
        //使用线程池的时候就需要由调用者加入一些任务让线程去执行
        void AddTask(Task * task)
        {
            _queue.push(task);
        }
    private:
        BlockingQueue<Task *> _queue;
        int _worker_count;
        std::vector<pthread_t> _workers;

        static void* ThreadEnter(void *arg)
        {
            Threadpool*pool=(Threadpool*)arg;
            while(1)
            {
                //循环中从阻塞队列中获取任务并执行任务
                Task* task=NULL;
                pool->_queue.pop(&task);
                //task是Mytask类型，因为Run是虚函数
                //执行的是子类，用户自定制的逻辑
                task->Run();
                delete task;
            }
        }

};

