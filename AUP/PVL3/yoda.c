#include<stdlib.h>

char *yoda(const char * const sentence);
int getLen(const char * const sentence,int flag);
void setStr(char *str1, const char * const sentence, int det, int src, int len);

char *yoda(const char * const sentence){
    
    int len, lstLen;

    len = getLen(sentence,0);
    lstLen = getLen(sentence+18,2);

    char *p = (char *)malloc(len);

    setStr(p, sentence, 0, len-lstLen-1, lstLen);
    p[lstLen] = ' ';
    setStr(p, sentence, lstLen+1, 0, len-lstLen-1);
    p[len-1] = sentence[len-1];
    if('a'<=p[0]){
        p[0] = p[0] - 32;
    }
    if(p[lstLen+1]<='Z'){
        p[lstLen+1] = p[lstLen+1] + 32;
    }


    return p;
}

int getLen(const char * const sentence,int flag){

    if(flag == 0){
        if(sentence[0] != '\0'){
                return getLen(sentence+1,0)+1;
        }
        else{
            return 0;
        }
    }
    if(flag == 2){
        if(sentence[0] != '\040'){
                return getLen(sentence-1,2)+1;
            }
            else{
                return -1;
            }    
    }
    return 0;
}

void setStr(char *str1, const char * const sentence, int det, int src, int len){

    if (len !=0){
        str1[det] = sentence[src];
        setStr(str1,sentence,det+1,src+1,len-1);
    }
}