#include<stdio.h>
#include<stdlib.h>
/*
数字>=0,
-1 +
-2 *
-3 =
符号对应其前两个变量
*/

long berechneUPN(int upn[]);

int main()
{

    int upn[4] = {10,10,-2, -3};
    
    printf("%ld\n", berechneUPN(upn));

    return 0;
}

long berechneUPN(int upn[]){
    int i = 3,fstOp=2;
    int lenOfUpn = 3;

    while (upn[i] != -3)    //获取-3即=的下标
    {
        if(upn[i]<0 && upn[i-1]>=0){    //获取第一个符号的下标
            fstOp = i;
        }
        lenOfUpn++;
        i++;
    }

    int a0[fstOp];      //把数字存入a0
    for (int i = 0; i < fstOp;i++){
        a0[i] = upn[i];
    }

    int j = 1;
    for (int i = fstOp; i < lenOfUpn; i++)
    {
        if(upn[i]==-1){
            a0[fstOp - j-1] = a0[fstOp - j] + a0[fstOp - j - 1];
            j++;
        }
        if(upn[i]==-2){
            a0[fstOp - j-1] = a0[fstOp - j] * a0[fstOp - j - 1];
            j++;
        }
        
    }
    
    return a0[0];
}

