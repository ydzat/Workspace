#include <stdio.h>
#include "gol.h"



/*
 Nicht schummeln!
 Alles was Sie wissen müssen steht in gol.c und gol.h
 
 Viele Erfolg
*/










































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































/*
 Output a part of the given panel on commandline
 Dose not return amithing
 par : parameter of the panel
 arr : the given panel
*/
void output(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]){
	printf("\f");
	for(int i=0;i<par.maxX;i++){
		for(int j=0;j<par.maxY;j++){
			
			if(arr[i][j][par.active] == dead){
				printf(".");
				//printf( "%d" ,neighborsCount(arr, i, j, active) );
			}
			else{
				printf("#");
				//printf( "%d" ,neighborsCount(arr, i, j, active) );
			}
		}
		printf("\n");
	}
}
