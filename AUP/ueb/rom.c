#include<stdlib.h>
#include<stdio.h>

/*
    罗马数字：
    1000    500 100 50  10  5   1
        M   D   C   L   X   V   I
    规则：
    M C X I 每个最多同时连续出现4次         千百十个
    D L V 仅允许单独出现     500 50 5
    从左到右阅读
    错误返回NULL
    如2018 = MMXVIII = 1000 + 1000 + 10 + 1 + 1 + 1
    0 = 空
    5000 = NULL  最大值为5000咯
    901 = DCCCCI = 500 + 100 + 100 + 100 + 100 + 1
*/

char *arab2rom(unsigned int arab);
int getLen(const int a);

int main(){

    char *s1 = arab2rom(2018);
    printf("%s\n", s1);
    free(s1);
    char *s2 = arab2rom(0);
    printf("%s\n", s2);
    free(s2);
    char *s3 = arab2rom(5000);
    if(s3 == NULL){
        printf("NULL\n");
    }
    //printf("%s\n", s3);
    free(s3);
    char *s4 = arab2rom(901);

    printf("%s\n", s4);
    free(s4);
    
  
    // char *s1 = arab2rom(2018);
    // printf("%s\n", s1);
    // free(s1);

    return 0;
}

char *arab2rom(unsigned int arab){
    if (arab == 0)
    {
        
        char *t = "";
        return t;
    }
    char *res = (char *)malloc(sizeof(char) * 2);
    int lenRes = 0;
    res[1] = '\0';
    int lenArab = getLen(arab);
    int num[lenArab];
    for (int i = 0; i < lenArab;i++){
        num[lenArab - 1 - i] = arab % 10;
        arab /= 10;
        
    }
    //printf("num[0] = %d, lenArab = %d\n", num[0], lenArab);
    
    
    for (int i = 0; i < lenArab; i++)
    {

            if (i == 0)
            {
                
                if (num[0] == 5)
                {
                    
                    if (lenArab >= 4)
                    {
                        free(res);
                        res = NULL;
                        return res;
                    }
                    else{
                    if(lenArab == 3){
                        res[0] = 'D';
                    }
                    if(lenArab == 2){
                        res[0] = 'L';
                    }
                    if(lenArab == 1){
                        res[0] = 'V';
                    }
                    lenRes++;
                }
            }
            else{
                if(num[0]>5){
                    if(lenArab>=4){
                        
                        res = NULL;
                        return res;
                    }
                    else{
                        res = (char *)realloc(res, sizeof(char) * (lenRes + num[0] - 4 + 1));
                        lenRes += num[0] - 4;
                        for (int j = 1; j < num[0]-4; j++)
                        {
                            if(lenArab == 3){
                                res[0] = 'D';
                                res[j] = 'C';
                            }
                            if(lenArab == 2){
                                res[0] = 'L';
                                res[j] = 'X';
                            }
                            if(lenArab == 1){
                                res[0] = 'V';
                                res[j] = 'I';
                            }
                        }
                    }
                }
                else{
                    res = (char *)realloc(res, sizeof(char) * (lenRes + num[0] + 1));
                    lenRes += num[0];
                    res[lenRes] = '\0';
                    for (int j = 0; j < num[0]; j++)
                    {
                        if (lenArab == 4)
                        {

                            res[j] = 'M';
                            //printf("res[j] = %c\n", res[j]);
                        }
                        if (lenArab == 3)
                        {

                            res[j] = 'C';
                        }
                        if (lenArab == 2)
                        {

                            res[j] = 'X';
                        }
                        if (lenArab == 1)
                        {

                            res[j] = 'I';
                        }
                    }
                        
                }
            }
        }
        if(i!=0){
            if(num[i]==5){
                res = (char *)realloc(res, sizeof(char) * (lenRes + 2));
                lenRes += 1;
                res[lenRes] = '\0';
                if(lenArab-i==3){
                    res[lenRes - 1] = 'D';
                }
                if(lenArab-i==2){
                    res[lenRes - 1] = 'L';
                }
                if(lenArab-i==1){
                    res[lenRes - 1] = 'V';
                }
            }
            else{
                if(num[i]>5){
                    res = (char *)realloc(res, sizeof(char) * (lenRes + num[i] - 4 + 1));
                    for (int j = lenRes+1; j < lenRes + num[i] - 4;j++){
                        if(lenArab-i==3){
                            res[lenRes] = 'D';
                            res[j] = 'C';

                        }
                        if(lenArab-i==2){
                            res[lenRes] = 'L';
                            res[j] = 'X';
                        }
                        if(lenArab-i==1){
                            res[lenRes] = 'V';
                            res[j] = 'I';
                            
                        }
                        
                    }

                    lenRes += num[i] - 4;
                    res[lenRes] = '\0';
                }
                else{
                    if(num[i]==0){
                        continue;
                    }
                    res= (char *)realloc(res, sizeof(char) * (lenRes + num[i] + 1));
                    for (int j = lenRes; j < lenRes + num[i];j++){
                        if(lenArab-i==3){
                            
                            res[j] = 'C';
                        }
                        if(lenArab-i==2){

                            res[j] = 'X';
                        }
                        if(lenArab-i==1){

                            res[j] = 'I';
                        }
                    }
                    
                    lenRes += num[i];
                    res[lenRes] = '\0';
                    
                }
            }
        }
    }
    return res;
}

int getLen(int a){
    int sum = 0;
    while(a){
        a /= 10;
        sum++;
    }
    return sum;
}