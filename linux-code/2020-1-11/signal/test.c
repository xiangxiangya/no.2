#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void myhandler(int signo)
{
    printf("%d\n",signo);
}
int main()
{
    int i=0;
    for(i=1;i<64;++i){
        signal(i,myhandler);
    }
    while(1);
    return 0;
}
