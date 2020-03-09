#include <stdio.h>
#include<unistd.h>
int main()
{
    int i=0;
    int pid=0;
    for(i=0;i<5;++i){
        pid=fork();
        if(pid==0){

        }
        else{

        }
    }
    while(1){}
    return 0;
}
