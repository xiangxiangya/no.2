#pragma once
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
static int CreateMem()
{
    int key=ftok(".",0x2);
    if(key<0){
        perror("ftok");
    }
    int shmid=shmget(key,1024,IPC_CREAT|0666);
    if(shmid<0){
        perror("shmget");
    }
    else{
        printf("shmget= %d\n",shmid);
    }
    return shmid;
}
