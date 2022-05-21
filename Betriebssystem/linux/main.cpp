/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<iostream>


int main(){
    pid_t p1, p2;
    //sem_t s;
    sem_t *s=NULL;
    //sem_init(&s,1,0);
    s = sem_open("NAMED_SEMAPHOR",0);

    p1 = fork();
    wait(NULL);
    if(p1==0){
        p2 = fork();
        wait(NULL);
        if(p2>0){
            printf("S\n");
            sem_post(s);
        }
        else{
            sem_wait(s);
            //sem_down(s);
            printf("ok1\n");
            printf("R\n");            printf("ok0\n");
            sem_post(s);
        }
    }
    else{
        sem_wait(s);
        printf("A\n");
        sem_post(s);
    }
    return 0;
}