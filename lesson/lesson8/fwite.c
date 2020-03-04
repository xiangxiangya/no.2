
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#include<stdlib.h>
int main()
{
    FILE * fd=fopen("tmp.txt","w"); 
    const char *str="hello world!\n";
    fwrite(str,1,strlen(str),fd);
    fclose(fd);
    return 0;
}
