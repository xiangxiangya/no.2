
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<malloc.h>
#include<sys/time.h>

#define SIZE 100000000

int64_t GetUs(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*1000000+tv.tv_usec;
}


void Calc(int *arr,int begin,int end){
    int i=0;
    for(i=begin;i<end;++i){
        arr[i]=arr[i]*arr[i];
    }
}

#if 0
int main()
{
    int *arr=(int *)malloc(sizeof(int)*SIZE);
    //记录开始时间
    int64_t beg=GetUs();
    Calc(arr,0,SIZE);
    //记录结束时间
    int64_t end=GetUs();
    //二者作差即Calc函数的执行时间
    printf("time :%ld\n",end-beg);
    return 0;
}
#endif

#define THREAD_NUM 2
  struct Arg    
    {    
      int beg;    
      int end;    
      int *arr;    
      } Arg; 

void *ThreadEntry(void *arg){
   struct Arg*p=(struct Arg*)arg ;
   Calc(p->arr,p->beg,p->end);
    return NULL;
}

//线程一算一半
//线程二算另一半
//
int main()
{
   int *arr=(int *)malloc(sizeof(int)*SIZE);
    pthread_t tid[THREAD_NUM];
   int i=0;
   struct Arg args[THREAD_NUM];
   int base=0;
   for(i=0;i<THREAD_NUM;++i){
       args[i].beg=base;
       args[i].end=base+SIZE/THREAD_NUM;
       args[i].arr=arr;
       base+=SIZE/THREAD_NUM;
   }
    int64_t beg=GetUs();
   for(i=0;i<THREAD_NUM;++i){
    pthread_create(&tid[i],NULL,ThreadEntry,&args[i]);
   }
   for(i=0;i<THREAD_NUM;++i){
       pthread_join(tid[i],NULL);
   }
    int64_t end=GetUs();
    printf("time :%ld\n",end-beg);
    return 0;
}
