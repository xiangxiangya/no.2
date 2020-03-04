#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
    int i=0;
    char buf[100]={0};
    char str[]="|/-\\";
    while(i<=100){
        printf("[%-100s][%d%%][%c]\r",buf,i,str[i%4]);
        fflush(stdout);
        buf[i++]='*';
        usleep(100000);

    } 
    printf("\n");
    return 0;
}
