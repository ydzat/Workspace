#include<stdio.h>
#include<stdlib.h>

/*
回文Palindrom

要求：一个字符串中可能含有多个回文，找到最长的
*/

typedef struct{
    int start;
    int ende;
} Interval;

int getLen(const char *p);


Interval *findeLPalindrom(const char *eingabe);

int main(){

    Interval *a0 = findeLPalindrom("abcabccbacba");
    Interval *a1 = findeLPalindrom("sfnebenabbaottoassrentner");

    printf("{%d,%d}\n", a0->start,a0->ende);
    printf("{%d,%d}\n", a1->start,a1->ende);

    return 0;
}

Interval *findeLPalindrom(const char *eingabe){
    Interval *a0=malloc(sizeof(Interval));    //大

    a0->start = -1;
    a0->ende = -1;


    int strlen = getLen(eingabe);
    

    
    for (int i = 0; i < strlen - 1;i++){
        for (int j = strlen - 1; j > 0;j--){
            if(eingabe[j] != eingabe[i]){
                continue;
            }
            if ((j - i) % 2 != 0)
            {
                int n = 1;
                for (int k = (j - i + 1) / 2 + i; k < j; k++)
                {
                    if (eingabe[k] != eingabe[(j - i + 1) / 2 + i - n])
                    {
                        
                        break;
                    }
                    else{
                        n++;
                        if (k == j - 1)
                        {
                            int len_a0 = a0->ende - a0->start;
                            int len_t = j - i;
                            if(len_t >len_a0){
                                a0->start = i;
                                a0->ende = j;

                                break;
                            }
                        }
                    }
                }
            }
            if((j-i)%2==0){

                for (int n = 1; n < (j - i) / 2;n++)
                {
                    if(eingabe[i+(j-i)/2+n] != eingabe[i+(j-i)/2-n]){
                        break;
                    }
                    else{
                        
                        if(n == (j-i)/2 - 1){
                            int len_a0 = a0->ende - a0->start;
                            int len_t = j - i;
                            if(len_t >len_a0){
                                a0->start = i;
                                a0->ende = j;
                            }
                        }
                    }
                }
            }
        }
    }

        return a0;

}

int getLen(const char *p){ //获取的是字符串中字符的个数
    int n = 0;
    while(*p!='\0'){
        p++;
        n++;
    }
    return n;
}