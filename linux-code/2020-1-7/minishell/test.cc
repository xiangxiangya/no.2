#include<stdio.h>
#include<iostream>
#include<string>
#include<unistd.h>
#include<sstream>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#if 0
int Str(char *In,char *Out)
{
    int count=0;
    char *p;
    p=strtok(In," ");
    while(p!=NULL){
        strcat(Out,p);
        strcat(Out,"\n");
        count++;
        p=strtok(NULL," ");
    }
    return count;
}
#endif



int main(int argc,char *argv[],char *env[])
{
    (void)argc;
    (void)argv;
    (void)env;
    while(1){
        printf("[aixaing@localhost minishell]$");
        char buf[1024]={0};
        int n=0;
        char ret[1024]={0};
        std::string s;
        std::cin>>s;
        std::stringstream ss(s);
        //n=Str(buf,ret);
        int i=0;
        for(i=0;i<argc;++i){
            ss>>argv[i];
        }
        int pid=fork();
        if(pid>0){
            wait(NULL);
        }
        else if(pid==0){
            execl("ls","ls",NULL);
            exit(0);
        }
}
    return 0;
}
