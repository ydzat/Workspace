/*
 * @Author: your name
 * @Date: 2021-12-09 21:24:37
 * @LastEditTime: 2021-12-09 21:55:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Workspace\AUP\dy0912\tribbles.c
 */
#include"tribbles.h"

typedef struct {
  unsigned int   wait_time;
  dim_t pos;
} dim_t_And_wait;


int tribble(trmapq_t (*map)[], dim_t dimensions, int numstart, dim_t start[]){

    trmapq_t now_pos = map[start.x][start.y];

    dim_t_And_wait *next_move = (dim_t_And_wait *)malloc(1*sizeof(dim_t_And_wait));
    dim_t *already_visited = (dim_t *)malloc(1 * sizeof(dim_t));
    unsigned int day = 0;

    switch(now_pos){
        case TR_U:
            return -1;
        case TR_V:
            find_next_move('V', now_pos, next_move, already_visited);
            break;
        case TR_W:
            find_next_move('W', now_pos, next_move, already_visited);
            break;
        case TR_Z:
            //to do something
            return day;
    }

    unsigned int dim_t_And_wait_length = get_length(next_move);

    dim_t_And_wait *t_next_move = next_move;

    for (int i = 0; i < dim_t_And_wait_length; i++){
        unsigned int wait_time = next_move[i].wait_time;

        if (i == dim_t_And_wait_length - 1){
            for (int j = 0; j < dim_t_And_wait_length; j++){
                t_next_move[j].wait_time--;
            }
            next_move = t_next_move;
            day++;
        }
        
        if(wait_time != 1){
            
            continue;
        }
        switch(next_move[i].pos){
            case TR_U:
                continue;
            case TR_V:
                find_next_move('V', now_pos, next_move, already_visited);
                break;
            case TR_W:
                find_next_move('W', now_pos, next_move, already_visited);
                break;
            case TR_Z:
                //to do something
                return day+1;
        }


    }

    free(already_visited);
    free(next_move);

    return 0;
}

void find_next_move(char flag, trmapq_t now_pos, dim_t_And_wait * next_move, dim_t * already_visited){
    
}

unsigned int get_length(dim_t_And_wait * p){
    int i = 0;
    dim_t_And_wait p_t = p;
    while(p != NULL){
        p_t++;
        i++;
    }
    return i;
}

unsigned int get_length(dim_t * p){
    int i = 0;
    dim_t p_t = p;
    while(p != NULL){
        p_t++;
        i++;
    }
    return i;
}