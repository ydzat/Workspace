#include<stdlib.h>
#include<stdio.h>

int *grep(const char *pattern, const char *text);
int getLen(const char *p);
/*
    字符串匹配：
    1.判断前一个字符串在第二个字符串中的起始位置
    2.问号‘?’表示通配符，例如当检索?a?，表示检索某一个单词，其第二个字符是a，所以返回的位置为第一个?的位置

*/

int main(){

    int *p1 = grep("Algo", "Algorithmus");
    printf("{%d}\n", p1[0]);
    free(p1);
    int *p2 = grep("komp", "Inkompetenzkompensationskompetenz");
    printf("{%d,%d,%d}\n", p2[0], p2[1], p2[2]);
    free(p2);
    int *p3 = grep("?a?", "Falafel");
    printf("{%d,%d}\n", p3[0], p3[1]);
    free(p3);
    int *p4 = grep("?a?", "aaaaa");

    //printf("%d\n%d\n%s\n%s\n", p1, p2, p3, p4);

    
    
    
    printf("{%d,%d,%d}\n", p4[0], p4[1], p4[2]);

    
    
    
    free(p4);
    return 0;
}

int *grep(const char *pattern, const char *text){
    //printf("--------pattern=%s---------\n", pattern);
    int *p = (int *)malloc(sizeof(int));
    
    int lenP = 0;
    p = NULL;
    int textLen = getLen(text), patternLen=getLen(pattern);
    
    for (int i = 0; i < textLen-patternLen+1; i++){
        if((text[i] == pattern[0]) || (pattern[0] == '?')){
            
            for (int j = 0; j < patternLen; j++)
            {
                //printf("i=%d,j=%d\n",i,j);
                if((text[i+j] != pattern[j]) && (pattern[j]!='?')){
                    break;
                }
                else{
                    if(j == patternLen-1){
                        p = (int *)realloc(p,sizeof(int)*(lenP+1));
                        
                        lenP++;
                        //p[lenP] = -1;
                        //printf("=======\n");
                        p[lenP - 1] = i;
                        //printf("p[lenP-1]= %d,lenP-1=%d\n", p[lenP - 1],lenP-1);
                    }
                }
            }
        }
    }
    //printf("p[0]======%d\n", p[0]);
    
    return p;
}

int getLen(const char *p){
    int n = 0;
    while(*p!='\0'){
        n++;
        p++;
    }
    return n;
}