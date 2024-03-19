#include<iostream>
#include<vector>

using namespace std;

struct process{
	string name;
	int burst_t;
	int wait_t;
	int TAT;
	
};

int main()
{
	int num_of_proc;
	cout<<"enter the number of process";
	cin>>num_of_proc;
	
	vector<process> proc(num_of_proc);
	for (int i=0; i< num_of_proc;i++)
	{
		cout<<"enter the burst time for process"<<(i+1)<<";";
		cin>>proc[i].burst_t;
		proc[i].name="P"+ to_string(i+1);
		proc[i].wait_t=0;
		proc[i].TAT=0;
	}
	for (int i=1; i< num_of_proc;i++){
			proc[i].wait_t=	proc[i-1].wait_t+proc[i-1].burst_t;
			proc[i].TAT=proc[i].wait_t+proc[i].burst_t;
	}
	
	//calc avg WT and TAT
	double avg_WT=0,avg_TAT=0;
	for (process&process:proc){
		avg_WT+=process.wait_t;
		avg_TAT+=process.TAT;
		
		
			}
			
	avg_WT/=num_of_proc;
	avg_TAT/=num_of_proc;
	//display result
	cout<<avg_WT;
	cout<<avg_TAT;
	
	
	
}
