/*
 * @Author: your name
 * @Date: 2021-12-09 20:56:58
 * @LastEditTime: 2021-12-09 21:23:29
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Workspace\AUP\dy0912\main.c
 */
#include<stdio.h>
#include"tribbles.h"

int main(){ dim_t msize = {8,8}; 
// Karte aus der Aufgabenbeschreibung 
    trmapq_t Map[8][8] = {
        {TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V}, 
        {TR_U, TR_U, TR_U, TR_U, TR_V, TR_V, TR_V, TR_V}, 
        {TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V}, 
        {TR_V, TR_V, TR_W, TR_W, TR_V, TR_V, TR_V, TR_V}, 
        {TR_V, TR_V, TR_V, TR_W, TR_W, TR_V, TR_V, TR_V}, 
        {TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V}, 
        {TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V}, 
        {TR_V, TR_Z, TR_V, TR_V, TR_V, TR_V, TR_V, TR_V},
    };

    dim_t start[1] = { {3,4} };
    int res = tribble(Map, msize, sizeof(start)/sizeof(dim_t), start); 
    if (res>=0) 
        printf("Tribbles reach destination after %d days.\n",res);
    else 
        printf("Tribbles never reach a destination\n");
    return 0;
}