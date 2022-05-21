#include"pcb.h"
#include<iostream>
#include<vector>
#include<deque>
#include<random>
#include<ctime>

using namespace std;

//Sort by time of arrival
void sort(vector<pcb>& pcbs) {
	int index;
	int n = pcbs.size();
	for (int i = 0; i < n; i++) {
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (pcbs[j].arrival_time < pcbs[i].arrival_time)
				index = j;
		}
		if (index != i){
			pcb temp;
			temp = pcbs[i];
			pcbs[i] = pcbs[index];
			pcbs[index] = temp;
		}
	}
}

void RR(vector<pcb>& pcbs, const float& rr) {
	vector<char> order;  //Record execution sequence

	deque<pcb> queue;  //Two terminal queue
	unsigned i = 1;
	int n = pcbs.size();

	//Sort by time of arrival
	sort(pcbs);

	//The first arriving process enters the queue
	queue.push_back(pcbs[0]);
    
	float time = pcbs[0].arrival_time;

	while (n!=0) {

		//Calculate current time
		if (!queue.empty()) {
			if (queue[0].remaining_time < rr)
				time += queue[0].remaining_time;
			else
				time += rr;
		}
		else {
			time = pcbs[i].arrival_time;
			queue.push_back(pcbs[i]);
            
			i++;
			if (queue[0].remaining_time < rr)
				time += queue[0].remaining_time;
			else
				time += rr;
		}

			
		//New processes arriving before the end of the process enter the queue
		while (i < pcbs.size() && pcbs[i].arrival_time <= time) {
			queue.push_back(pcbs[i]);
			i++;
		}
		
		order.push_back(queue[0].name);
        
        
        

		//The unfinished process is put into the end of the queue, otherwise it is deleted from the queue
		if (queue[0].crt(rr)) { 
			pcb t = queue[0];
            
			queue.pop_front();
			queue.push_back(t);
		}
		else {
			for (unsigned j = 0; j < pcbs.size(); j++) {
				if (pcbs[j].name == queue[0].name) {
					pcbs[j].cft(time);
				}
			}
            
			queue.pop_front();
			n--;
		}
	}

	//Print execution sequence
	cout << "Execution sequence:";
	for (auto i : order)
		cout << i << ' ';
    cout << endl;
    
    
	cout << endl;
}

int main() {
	int n;
	float rr;

	//Enter process information and display it
	cout << "Number of input processes:";
	cin >> n;
	vector<pcb> pcbs(n);
	cout << "\n Enter the process name and arrival time and server time" << endl;
	char name; float at; float st;

	//uniform_int_distribution<unsigned> u(1, 5);  //Generating random numbers with uniform distribution from 1 to 5
	//default_random_engine e(time(0));
	for (int i = 0; i < n; i++) {
		cin >> name >> at >> st ;
		//st = float(u(e));
		pcbs[i] = pcb(name, at, st);
	}
	for (int i = 0; i < n; i++) {
		pcbs[i].display();
	}

	//Enter the time slice size and execute RR
	cout << "\n Input time slice size:";
	cin >> rr;
	cout << "\n";
	RR(pcbs, rr);

	//Calculate (average) turnaround time, (average) weighted turnaround time
	float sum1 = 0.0, sum2 = 0.0;
	for (int i = 0; i < n; i++) {
		cout << "No" << pcbs[i].read_name() << "\t"
			<< "Turnaround time:" << pcbs[i].ct1() << "\t"
			<< "Turnaround time with rights:" << pcbs[i].ct2() << endl;
		sum1 += pcbs[i].ct1();
		sum2 += pcbs[i].ct2();
	}
	cout << "Average turnaround time:" << sum1 / float(n) << endl;
	cout << "Average weighted turnover time:" << sum2 / float(n) << endl;

	return 0;
}