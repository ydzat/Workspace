#ifndef PCB_H
#define PCB_H
#include<vector>
class pcb {
	friend void sort(std::vector<pcb>&);
	friend void RR(std::vector<pcb>&, const float&);
public:
	pcb() = default;
	pcb(char a, float b, float c) :name(a), arrival_time(b), service_time(c), remaining_time(c) {}
private:
	char name;
	float arrival_time;      //arrival time
	float service_time;      //service time 
	float remaining_time;    //Remaining service time
	float finish_time;       //End time
	float t1;                //Turnaround time
	float t2;                //Turnaround time with rights
public:
	void display() const;    //Display process information
	char read_name() const;  //Read name
	bool crt(float rr);      //Calculate remaining time
	void cft(float time);    //Calculation end time
	float ct1();             //Calculate turnaround time
	float ct2();             //Calculate weighted turnaround time
};
#endif