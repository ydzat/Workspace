#include <stdio.h>
#include <unistd.h>
#include "gol/gol.h"

void inita(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);

void outputa(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);

int updatea(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);

int main (){
	//Set the dimensions of the panel
	//Zone 0 is active, zone 1 is inactive. So we can calculate the new panel in zone 1.
	//设置面板的尺寸
	//区域0处于活动状态，区域1处于非活动状态。 因此，我们可以计算区域1中的新面板
	//struct panelParams par = {22, 80, 2, 0};
	struct panelParams par = {10, 15, 2, 0};
	//create the panel: x, y are the dimensions, we need 2 versions created in the 3rd dimension. One for the current/active one for calculating the update.
	//创建面板：x，y是尺寸，我们需要在第3维中创建2个版本。 一个用于当前/活动一个用于计算更新。
	enum field panel[par.maxX][par.maxY][par.maxAge];

	
	//Initialize the panel’s active zone with “dead”. The not active zone is overwritten later on so we do not need to initialize it.
	//用“死区”初始化面板的活动区域。 稍后将覆盖非活动区域，因此我们不需要对其进行初始化。
	inita(par, panel);
	
	//Write a blinker in the panel’s active zone.
	//在面板的活动区域中编写一个信号灯
	panel[3][3][par.active] = alive;
	panel[3][4][par.active] = alive;
	panel[3][5][par.active] = alive;

	//Write a glider in the panel’s active zone.
	//在面板的活动区域中编写滑翔机。
	panel[11][10][par.active] = alive;
	panel[12][11][par.active] = alive;
	panel[12][12][par.active] = alive;
	panel[11][12][par.active] = alive;
	panel[10][12][par.active] = alive;

	
	//Run many iterations
	for(int i=0; i<10000; i++){
		//Output the active part of the panel
		//output(par, panel);
		outputa(par,panel);
		
		//Update the not active part of the panel and switch the active and not active part
		//更新面板的非活动部分，并切换活动和非活动部分
		//par.active = update(par, panel);
		par.active = updatea(par,panel);
		sleep(1);
	}
	
	return 0;
}

void inita(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]){
	for (int i = 0; i < par.maxX; i++){
		for (int j = 0; j < par.maxY; j++){
			arr[i][j][par.active] = dead;
		}
	}
}

void outputa(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]){
	for (int i = 0; i < par.maxX; i++){
		if(i==0){
			printf("0");
		}
		for (int j = 0; j < par.maxY; j++){
			if(arr[i][j][par.active] == alive){
				printf("#");

			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
}

int updatea(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]){
	for (int i = 0; i < par.maxX; i++){
		for (int j = 0; j < par.maxY; j++){
			if(arr[i][j][par.active] == alive){
				if(arr[i][j+1][par.active] == alive && arr[i][j-1][par.active] == alive){
					return par.active;
				}
				if(arr[i][j+1][par.active] == alive && arr[i+1][j][par.active] == alive){
					return par.active;
				}
				if(arr[i][j+1][par.active] == alive && arr[i-1][j][par.active] == alive){
					return par.active;
				}
				if(arr[i-1][j][par.active] == alive && arr[i][j-1][par.active] == alive){
					return par.active;
				}
				if(arr[i-1][j][par.active] == alive && arr[i+1][j][par.active] == alive){
					return par.active;
				}
				if(arr[i][j+1][par.active] == alive && arr[i+1][j][par.active] == alive){
					return par.active;
				}
				else{
					
					return  par.active - 1;
				}
			}
		}
	}
	return 0;
}