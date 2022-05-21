#include <iostream>

#include "CGVector.h"
#include "CGMatrix.h"

using namespace std;
void test_matrix_constructor(){

	CGMatrix4x4 M(1,2,3);
	// Test memory alignment:
	float data [16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 1,2,3,1};
	float* m = (float*)(void*)&M;
	bool passed = true;
	for(int i = 0; i< 16;i++){
		if(fabsf(m[i] - data[i]) > 0.0001f){
			passed = false;
		}
	}
	if(passed){
		cout << "TEST_MATRIX_CONSTRUCTOR:      [Passed]\n";
	}else{
		cout << "TEST_MATRIX_CONSTRUCTOR:      [Failed]\n";
	}

}

void test_matrix_print(){

	CGMatrix4x4 M(1,2,3);
	// Test print:
	cout <<"M.print() should look something like this:\n";
	cout <<"("<<1.0f<<' '<<0.0f<<' '<<0.0f<<' '<<1.0f<<")\n";
	cout <<"("<<0.0f<<' '<<1.0f<<' '<<0.0f<<' '<<2.0f<<")\n";
	cout <<"("<<0.0f<<' '<<0.0f<<' '<<1.0f<<' '<<3.0f<<")\n";
	cout <<"("<<0.0f<<' '<<0.0f<<' '<<0.0f<<' '<<1.0f<<")\n";
	cout <<"---------------------------------------------\n";
	cout <<"M.print():\n";
	M.print();

}

void test_matrix_at(){
	CGMatrix4x4 M(1.0f);
	M.at(2,2) = 42;
	M.at(1,3) = 23;

	float data [16] = {1,0,0,0, 0,1,0,23, 0,0,42,0, 0,0,0,1};
	float* m = (float*)(void*)&M;
	bool passed = true;
	for(int i = 0; i< 16;i++){
		if(fabsf(m[i] - data[i]) > 0.0001f){
			passed = false;
		}
	}
	if(passed){
		cout << "TEST_MATRIX_AT:               [Passed]\n";
	}else{
		cout << "TEST_MATRIX_AT:               [Failed]\n";
	}
}

void test_matrix_transpose(){
	CGMatrix4x4 M(1.0f,2.0f,3.0f);
	M.transpose();
	float data [16] = {1,0,0,1, 0,1,0,2, 0,0,1,3, 0,0,0,1};
	float* m = (float*)(void*)&M;
	bool passed = true;
	for(int i = 0; i< 16;i++){
		if(fabsf(m[i] - data[i]) > 0.0001f){
			passed = false;
		}
	}
	if(passed){
		cout << "TEST_MATRIX_TRANSPOSE:        [Passed]\n";
	}else{
		cout << "TEST_MATRIX_TRANSPOSE:        [Failed]\n";
	}
}


void test_matrix_vector_mult(){
	CGMatrix4x4 M(1.0f,2.0f,3.0f);
	CGVec4 v(3.0f,2.0f,1.0f);
	CGVec4 result(4.0f,4.0f,4.0f,1.0f);
	v = M*v;

	bool passed = true;
	for(unsigned int i = 0; i< 4;i++){
		if(fabsf(v[i] - result[i]) > 0.0001f){
			passed = false;
		}
	}
	if(passed){
		cout << "TEST_MATRIX_VECTOR_MULT:      [Passed]\n";
	}else{
		cout << "TEST_MATRIX_VECTOR_MULT:      [Failed]\n";
	}
}

void test_matrix_matrix_mult(){
	CGMatrix4x4 M(1.0f,2.0f,3.0f);
	CGMatrix4x4 M2(1.0f,2.0f,3.0f);
	CGMatrix4x4 M3(2.0f);
	M = M * M3;

	float data [16] = {2,0,0,0, 0,2,0,0, 0,0,2,0, 2,4,6,2};
	float* m = (float*)(void*)&M;
	bool passed = true;
	for(int i = 0; i< 16;i++){
		if(fabsf(m[i] - data[i]) > 0.0001f){
			passed = false;
		}
	}
	if(passed){
		cout << "TEST_MATRIX_MATRIX_MULT:      [Passed]\n";
	}else{
		cout << "TEST_MATRIX_MATRIX_MULT:      [Failed]\n";
	}
}




int main()
{
	test_matrix_constructor();
	test_matrix_at();
	test_matrix_transpose();
	test_matrix_vector_mult();
	test_matrix_matrix_mult();
	test_matrix_print();
	cout << "\nPress Enter to continue!"<<endl;
	getchar();
	return  0;
}
