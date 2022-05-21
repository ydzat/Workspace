/*
 * @Author: your name
 * @Date: 2021-07-25 02:10:52
 * @LastEditTime: 2021-10-20 21:15:05
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \diac:\Users\ydzat\OneDrive\Workspace\AUP\Ue6\main.cpp
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int count(char *arr);
int strlen(char* str);
char *sToL(char* str);

int main(){
    //int anzahl;
    char num[5];
    string s = "abcdefg";
    scanf("%d",num[5]);
    //printf("wie viele Nummer?\n");
    //scanf("%d",&anzahl);

    //char *nr = (char * )malloc(5);
    for(int i = 0; i<5;i++){
        
        cout<<"input num"<<endl;

        scanf("%c",&num[i]);
        fflush(stdin);
    }
    for(int i =0;i<5;i++){
    cout<<"string ist "<<num[i]<<endl;}
    //b)
    //scanf("%d",num[5]);

    printf("es gibt %d mal Elemente\n",count(&num[0]));
    printf("length of str ist:%d\n",strlen(&s[0]));
    printf("smile to large %s\n",sToL(&s[0]));
    printf("%s\n",sToL(&num[0]));


    return 0;
}


//c)
int count(char *arr){
    int count=0;
    //cout<<"arr = "<<*arr<<endl;
    while(true){
        if(*arr == NULL){
            return count;
        }
        arr+=1;
        count++;
    }
    return 0;

}

// char *s 
//s= "abcd";

int strlen(char* str){
    int count = 0;
    while(true){
        if (*str == NULL){
            return count;
        }
        str+=1;
        count ++;
    }
    return 0;
}

char *sToL(char* str){
    char *L=(char *)malloc(strlen(&str));
    while(*str!=NULL){
        *L==*str+32;
        str+=1;

    }
    return str;
}