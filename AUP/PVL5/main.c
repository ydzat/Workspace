#include"cpu.c"
#include<stdio.h>
#include<stdbool.h>

int main(){

    struct reg *cpuMo;
    
    
    printf("==== \n");
    // for(int i = 0 ; i < 8; i ++){
    //     cpuMo->fa&(1<<i)
    // }
    cpuMo->fa = 2;
    cpuMo->pc = 1;


    
    unsigned char data[128]={1};

    // for(int i = 0 ; i < 128; i++){
    //     data[i] = i;
    //     printf("%d -> ",i);
    //     for(int j = 7 ; j >= 0; j --){
    //         printf("%d",(data[i]>>j)&1);
    //         if(j == 4){
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }
    
    uint16_t cmd[256];
    cmd[cpuMo->pc] = 21761;
    printf("data+1 = %d\n",data[0]);
    bool temp = cpu(cpuMo, data, cmd);
    printf("new -> %d\n",cmd[cpuMo->pc]);
    printf("new registers->fa = %d\n",cpuMo->fa);
    printf("%d\n",temp);
    return 0;
}