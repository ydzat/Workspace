#include<stdio.h>
#include<unistd.h>
#include"gol.h"

int main(){

    struct cell c = {10,15,2,0};
    enum field fe [c.maxX][c.maxY][c.maxAge];

    init(c,fe);


}