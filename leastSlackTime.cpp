#include<bits/stdc++.h>
using namespace std;
typedef struct job{
	int rt,adl,remainingTime,slackTime;
}JOB;
struct task{
	int rt,ct,tp,dl,noOfjob,k,taskNumber;
	JOB job[100];
};

typedef struct task TASK;
struct Compare{
	bool operator()(const TASK* task1,const TASK* task2)
    {
	   return task1->job[task1->k].slackTime>task2->job[task2->k].slackTime;
    }
};

int main(){

	stack<TASK> stack;
	// Compare is used to insert data into priorityqueue in increasing order of slack time of a job
	priority_queue<TASK*,vector<TASK*>,Compare> pQueue;
	int n,i,j;
	cout<<" Least Slack Time Algorithm \n";
	cout<<"enter no. of task\n";
	cin>>n;
	TASK task[n];
	cout<<"Please enter only integer value(no decimal value)\n";
	cout<<"enter release time, computation time,time period,deadline of each task\n";
	
	for(int i=0;i<n;i++){
		cin>>task[i].rt>>task[i].ct>>task[i].tp>>task[i].dl;
		task[i].k=0;//it is used to initialize k value 
	}

	//to calculate hyper period
	int hyperPeriod=task[0].tp;

	for(int i=0;i<n-1;i++){
		hyperPeriod=(hyperPeriod*task[i+1].tp)/(__gcd(hyperPeriod,task[i+1].tp));
	}
	// cout<<hyperPeriod;

	for(int i=0;i<n;i++){
		int jobTimePeriod=task[i].rt,j=0;
        task[i].taskNumber=i+1;
        //calculating relative deadline of each job with its absolute deadline
		while(jobTimePeriod<hyperPeriod){
			//task[i].rtime[j]=j*task[i].tp;
			task[i].job[j].rt=j*task[i].tp;
			task[i].job[j].remainingTime=task[i].ct;
			//task[i].adl[j]=task[i].rtime[j]+task[i].dl;
            task[i].job[j].adl=task[i].job[j].rt+task[i].dl;
			j++;
			jobTimePeriod=j*task[i].tp;
		}
		task[i].noOfjob=j;
	}
	cout<<"Hyperperiod= "<<hyperPeriod<<" \n";

	for(i=0;i<hyperPeriod;)
	{
	    for(j=0;j<n;j++)
	    {
	    	//Those jobs whose release time equals to i are pushed into stack
	    	if(task[j].job[task[j].k].rt==i)
	    	{
	    		if(task[j].k<task[j].noOfjob)
	    		{
	    			task[j].job[task[j].k].slackTime=task[j].job[task[j].k].adl-i-task[j].job[task[j].k].remainingTime;
                    pQueue.push(&task[j]);
	    		}
	    	}
	    }

	    // cout<<" "<<tempTask->k<<" "<<tempTask->noOfjob;
	    if(!pQueue.empty())
	    {
	        TASK* tempTask=pQueue.top();
	        int value=tempTask->job[tempTask->k].remainingTime;
	        //cout<<"value= "<<value<<"\n";
	    	if(value==0 )
	    	{
	    	    tempTask->k++;
	    	    pQueue.pop();
	        }
	        else if(value!=0)
	        {
	    	   cout<<"T"<<tempTask->taskNumber<<(tempTask->k+1)<<" ";
	    	   tempTask->job[tempTask->k].remainingTime-=1;
	    	   i++;
	        }
	    }
	    else
	    	i++;
	}
	cout<<"\n\n";
	for(int i=0;i<n;i++){
		if(task[i].k==task[i].noOfjob){
			cout<<"All jobs of Task "<<i+1<<" has been scheduled \n";
		}else{
			cout<<"Jobs of Task "<<i+1<<" ";
			//cout<<task[i].k+1<<task[i].noOfjob<<" ";
			for(int j=task[i].k+1;j<=task[i].noOfjob;j++){
				cout<<"J"<<i+1<<j<<" ";
			}
			cout<<"could not be scheduled\n";
		}
	}
}