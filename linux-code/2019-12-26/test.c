#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#include<fcntl.h>
#include<unistd.h>
#if 0
int main()
{
#if 0
    if(lseek(0,0,1)==-1){

        printf("no\n");
    }
    else{
        printf("yes\n");
    }
#endif

#if 0
    int fd=open("./a.txt",O_CREAT|O_RDWR,0777);
    char buf[]="hello world\n";
    write(fd,buf,sizeof(buf));
    lseek(fd,23,SEEK_SET);
    write(fd,"hehehe",6);
#endif

#if 0
    char buf[10]={0};
    
    read(STDIN_FILENO,buf,6);
    write(STDOUT_FILENO,buf,sizeof(buf));
    while(1){}
#endif

    //int fd=open("./a.txt",O_CREAT|O_RDWR);
    //int ret=fcntl(fd,F_GETFD);
    //int ret1=fcntl(fd,F_GETFL);
    //printf("%d\n",fd);
    //printf("%d\n",ret);


    return 0;
}
#endif


int main(int argc,char *argv[],char * envp[])
{
    int i=0;
#if 0
    for(i;envp[i];++i){
        printf("%s\n",envp[i]);
    }
#endif

    for(i=0;i<argc;i++){
        printf("[%d]=[%s]",i,argv[i]);
    }
    return 0;

}
