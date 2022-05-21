#pragma once
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "CGVector.h"

static float CG_DUMMY_FLOAT = 0;

class CGMatrix4x4{
	
	float matrix_arr[4][4];

public:
	CGMatrix4x4();

	CGMatrix4x4( float v);

	CGMatrix4x4(float x, float y, float z);
	
	void print() const;

	float& at(unsigned int c, unsigned int r);

	const float& at(unsigned int c, unsigned int r) const;

	void transpose();

	CGVec4 operator*(const CGVec4& b) const;

	CGMatrix4x4 operator*(const CGMatrix4x4& b) const;

};

//----------------------------------------------

CGMatrix4x4::CGMatrix4x4(){
	
}

CGMatrix4x4::CGMatrix4x4( float v){

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i == j){
				matrix_arr[i][j] = v;
			}
			else{
				matrix_arr[i][j] = 0;
			}
		}
	}
}

CGMatrix4x4::CGMatrix4x4(float x, float y, float z){

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i == j){
				matrix_arr[i][j] = 1;
			}
			else{
				matrix_arr[i][j] = 0;
			}
		}
	}
	matrix_arr[3][0] = x;
	matrix_arr[3][1] = y;
	matrix_arr[3][2] = z;

}

void CGMatrix4x4::print() const{

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%f ",matrix_arr[i][j]);
		}
		printf("\n");
	}
}

float& CGMatrix4x4::at(unsigned int c, unsigned int r){

	return *(matrix_arr[c]+r);
}

const float& CGMatrix4x4::at(unsigned int c, unsigned int r) const{

	return matrix_arr[r][c];
}

void CGMatrix4x4::transpose(){

	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 4; j++)
		{
			std::swap(matrix_arr[i][j], matrix_arr[j][i]);
		}
	}
}

CGVec4 CGMatrix4x4::operator*(const CGVec4& b) const{

	CGVec4 result;

	for(int i = 0; i < 4; i++){
		float ans = 0;
		for(int j = 0; j < 4; j++){
			ans = ans + matrix_arr[j][i] * b[j];
		}
		result[i] = ans;
	}

	return result;
}

CGMatrix4x4 CGMatrix4x4::operator*(const CGMatrix4x4& b) const{

	CGMatrix4x4 result;
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			float ans = 0;
			for(int k = 0; k < 4; k++){
				ans = ans + matrix_arr[k][i] * (b.matrix_arr[j][k]);
			}
			result.at(j,i) = ans;
		}
	}

	return result;
}