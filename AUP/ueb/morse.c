#include<stdlib.h>
#include<stdio.h>

/*
短信号 *
长信号 -
间隔 空格
*-   A
*-** L
--*  G
---  O
***  S
*/

char *parse_morse(const char *morsecode);

int getLen(const char *p);
char get1word(const char *p);

int main(){

    char *s1 = parse_morse("--- *-** --* *-"),*s2=parse_morse("--* *-** *- ***"),*s3=parse_morse("*** ---");


    printf("%s\n", s1);
    free(s1);
    printf("%s\n", s2);
    free(s2);
    printf("%s\n", s3);
    free(s3);
    return 0;
}

char *parse_morse(const char *morsecode){
    char *res = (char *)malloc(2*sizeof(char));
    res[1] = '\0';
    int resLen = 0;

    int strLen = getLen(morsecode);
    
    for (int i = 0; i < strLen; i++)
    {

        if(i==0){
            
            res[0] = get1word(morsecode);
            resLen++;
        }

        if(morsecode[i]!=' '){
            continue;
        }else{
            res = (char *)realloc(res, sizeof(char) * (resLen + 2));

            res[resLen] = get1word(morsecode + i+1);
            res[resLen + 1] = '\0';
            resLen++;
        }
    }
    //printf("res[0]=%c,res[1]=%c\n", res[0], res[1]);
    return res;
}

int getLen(const char *p){
    int n = 0;
    while(*p!='\0'){
        n++;
        p++;
    }
    return n;
}

char get1word(const char *p){
    char t[5] = {'0'};
    int wordLen = 0;

    while ((*p != ' ') && (*p!='\0'))
    {

        t[wordLen] = p[0];
        wordLen++;
        p++;
    }

    if (wordLen == 2)
    {
        return 'A';
    }
    if(wordLen ==4){
        return 'L';
    }
    if(t[0]=='-' && t[1]=='-' && t[2]=='*'){
        return 'G';
    }
    if(t[0]=='-'&&t[1]=='-'&&t[2]=='-'){
        
        return 'O';
    }
    if(t[0]=='*'&&t[1]=='*'&&t[2]=='*'){
        return 'S';
    }
    return '\0';
}