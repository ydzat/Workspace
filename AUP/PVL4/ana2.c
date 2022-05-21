#include<stdio.h>
#include<stdlib.h>

void ana(char * arr, char **dict, int dictLen);

struct Argument{
    char *wort;
    char **dict;
    int len;
    void * (*fuc1)(struct Argument * obj);
};

void *setWort(struct Argument *obj);
int getLen(char *arr);

int main(){
    
    struct Argument demo;
    demo.fuc1 = &setWort;
    int dictLen;
    demo.fuc1(&demo);
    dictLen = demo.len-1;
    ana(demo.wort,demo.dict,dictLen);

    return 0;
}

void ana(char *arr, char **dict, int dictLen){

    int wort[26]={0},maxLenInDict=0;
    char *p;
    char **res = (char **)malloc((sizeof(char *)));

    for(int i = 0; i < dictLen-1 ; i++){
        if( getLen(dict[i]) > getLen(dict[i+1])) {
            maxLenInDict = getLen(dict[i]);
        }
    }

    char d[dictLen][maxLenInDict+1] ;
    int wortLen[dictLen];

    for(int i = 0; i< dictLen ; i++){
        wortLen[i] = getLen(dict[i]);
        for(int j = 0; j<wortLen[i];j++){
            
            d[i][j] = dict[i][j];
            if(dict[i][j] <= 'Z'){
                d[i][j] = d[i][j] + 32;
            }
            if(j == wortLen[i]-1){
                d[i][j+1] = '\0';
                
            }
            
        }
        
    }

    p = arr;
    int satzLen=0,satzLenOhneLeer=0;

    satzLen = getLen(p);
    
    for(int i = 0; i < satzLen; i++){
        
        if(p[i]!='\040'){
            satzLenOhneLeer++;
            if(p[i]<='Z'){
                wort[(p[i]- 65)%26]++;
            }
            if(p[i]>='a'){
                wort[(p[i]- 97)%26]++;
            }
            
        }
    }

    int *elem = (int*)malloc(sizeof(int)), count = 0;
    for(int i = 0; i < dictLen ; i ++){
        elem = (int *)realloc(elem,sizeof(int)*(i+1));

        int tCount[26]={0};
        for(int j = 0; j < getLen(dict[i]); j++){
            int aph = -1;
            if((d[i][j]-96)%26 == 0){
                aph = 26;
            }
            else{
                aph = (d[i][j]-96)%26;
            }
            if(wort[aph - 1] == 0){
                tCount[aph - 1] = 0;
                elem[i] = 0;
                break;
            }
            else{
                tCount[aph - 1]++;
                
                if(tCount[aph - 1] > wort[aph - 1]){
                    
                    elem[i] = 0;
                    break;
                }
                else{
                    
                    elem[i] = 1;
                }
            }
            
            
        }
    }
    for(int i = 0; i < dictLen ; i ++){
        printf("marked1: elem[%d] = %d\n",i,elem[i]);
        // printf("wortLen[%d] = %d\n",i,wortLen[i]);
        if(elem[i]==1){
            count++;
        }
    }
    // printf("count = %d",count);
    // char **res = (char *)malloc(sizeof(char *));
    // for(int i = 0 ; i < dictLen ; i++){
    //     if(elem[i] != 1){
    //         continue;
    //     }
    //     else{
    //         for(int j = i ; j < dictLen ; j++){
    //             if(elem[j] != 1){
    //                 continue;
    //             }
    //             else{

    //             }
    //     }
    // }



    free(p);

}

char *getStr(){
    int strLen = 5;
    char ch;
    char *str = (char *)malloc(sizeof(char *) * strLen);

    int count = 0;
    do{
        ch = getchar();
        count++;
        if(count >= strLen){
            str = (char *)realloc(str, sizeof(char *) * (++strLen));

        }
        str[count - 1] = ch;

    }while(ch != '\n');

    return str;
}

void * setWort(struct Argument *obj){
    char *Arg[] = {
        "Sxzytwqp Klj Yrtd",
        "Abc",
        "And",
        "Def",
        "Dxz",
        "k",
        "kx",
        "Ljsrt",
        "lt",
        "pt",
        "Ptyywq",
        "y",
        "Ywjsrq",
        "Zd",
        "zzx",
        '\0'
    };
    int dictLen = 0;
    obj -> wort = Arg[0];

    while(1){

        if(Arg[dictLen] == '\0'){
            break;
        }
        else{
            dictLen++;
        }
    }
    obj -> len = dictLen;

    for(int i = 0; i < dictLen; i++){
        if(i == dictLen-1){
            obj -> dict[i] = '\0';
            break;
        }
        if(i==0)
        {
            obj -> dict = (char**)malloc(sizeof(char*));
        }
        if(obj->dict != NULL){
            obj -> dict = (char **)realloc(obj->dict, sizeof(char*)*(i+1));
        }

        obj -> dict[i] = (char*)malloc(sizeof(char)*(getLen(Arg[i+1])));
        obj -> dict[i] = Arg[i+1];

    }
}

int getLen(char *arr){
    if(arr[0] != '\0'){
        return getLen(arr+1)+1;
    }
    else{
        return 0;
    }
}

