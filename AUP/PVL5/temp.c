#include<stdio.h>
#include<stdlib.h>

double pow(double x, double y);

int main(){

    int t = pow(2,3);

    printf("===%d\n",t);
    return 0;
}

// double pow(double x, double y){
//     printf("11111\n");
//     double sum = 1;
    
//     for(int i = 1; i <= y; i++){
//         sum = sum * x;
        
//     }
//     printf("-----%d\n",sum);
//     return sum;
// }