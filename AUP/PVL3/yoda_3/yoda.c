#include<stdlib.h>

char *yoda(const char * const sentence);
int getLen(const char * const sentence,int flag);
void setStr(char *str1, const char * const sentence, int det, int src, int len);

char *yoda(const char * const sentence){
    
    int len, fstLen, lstLen;

    len = getLen(sentence,0);
    fstLen = getLen(sentence,1);
    lstLen = getLen(sentence+18,2);

    char *p = (char *)malloc(len);

    setStr(p, sentence, 0, len-lstLen-1, lstLen);
    setStr(p, sentence, lstLen, fstLen, len-fstLen-lstLen-1);
    setStr(p, sentence, len-fstLen-1, 0, fstLen);
    p[len-1] = sentence[len-1];

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
    if(flag == 1){
        if(sentence[0] != '\040'){
                return getLen(sentence+1,1)+1;
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