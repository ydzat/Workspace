#include"pcb.h"
#include<iostream>

using namespace std;

//Display process information
void pcb::display() const {
	cout << "name:" << name << "\t"
		<< "arrival time:" << arrival_time << "\t"
		<< "Service time:" << service_time << endl;
}

//Calculate the remaining time, return false if the time is less than one time slice, otherwise return true
bool pcb::crt(float rr) {   
	if (remaining_time <= rr)
		return false;
	else {
		remaining_time -= rr;
		return true;
	}
}

//Calculation end time
void pcb::cft(float time) {
	finish_time = time;
}

//Calculate turnaround time
float pcb::ct1() {
	return finish_time - arrival_time;
}

//Calculate weighted turnaround time
float pcb::ct2() {
	return (finish_time - arrival_time) / service_time;
}

//Read process name
char pcb::read_name() const {
	return name;
}