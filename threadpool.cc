#include"threadpool.hpp"

//这个类由用户自己定制，想干什么都是由用户自己决定
class MyTask :public Task
{
    public:
        MyTask(int id)
            :_id(id)
        {}
        //重写Run函数去执行用户自定制的逻辑
        void Run()
        {
            printf("%d\n",_id);
        }
    private:
        int _id;
};

int main()
{
    Threadpool pool(10);//创建十个线程
    int i=0;
    for(i=0;i<30;++i){
        //将自己定义的类交给线程池去进行创建、管理、调度
        pool.AddTask(new MyTask(i));
            usleep(789789);
    }
    return 0;
}
