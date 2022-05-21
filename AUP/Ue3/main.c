#include<stdio.h>

//参数为一个句子
char *yoda(const char * const sentence);

int main(){
    char * p = "Die Macht ist stark";
    char *p2;
    printf("Original: %s\n",p);
    p2 = yoda(p);
    printf("yoda: %s",p2);

    return 0;
}

char *yoda(const char * const sentence){
    char *p,*p1="",*p2;
    int addr[4];
    //addr[0] = &p[0];
    p = sentence;

    if(p1[0] == ' ' && ){
        p1 = &p1[0];
    }
    else{
        yoda(p+1);
    }

    //--------------------------此时已经将p1指向最后
    if (p2[0] == '\0'){
        printf("gelaeuft!\n");
        p2 = &p2[0];
    }
    else{
        yoda(p+1);
    }
    //-------------------------
    
    // printf("&p[0]+1 = %s\n",&p[0]+1);
    // printf("p[1] = %c\n",p[1]);
    // printf("p = %s\n",p);
    // printf("p+1 = %s\n",p+1);

//    p2 = yoda(p2);
    


    return p;
}