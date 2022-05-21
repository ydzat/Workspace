
#include"yoda.c"

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int max(int a, int b);
int max(int a, int b, int c);
int num(int a);

int main(){

    const char *p = "ich bin dene Vater!";
    const char *p1 = "Ich bin dene vater!";
    const char *p2 = "ich bin dene vater!";
    const char *p3 = "Ich bin dene Vater!";

    char *o=yoda(p);
    int max = max(a,b);
    cout<<"out----->"<<o<<endl;
    cout<<"p1 ------>"<<yoda(p1)<<endl;
    cout<<"p2 ------>"<<yoda(p2)<<endl;
    cout<<"p3 ------>"<<yoda(p3)<<endl;

    return 0;
}


int max(int a, int b){

    return max;
}