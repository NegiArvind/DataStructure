#include<bits/stdc++.h>
using namespace std;
struct task{
	int rt,ct,tp,dl,noOfjob;
	int job[1000],rtime[1000],adl[1000],k;
};
typedef struct task TASK;

int main(){

    stack<TASK> taskStack;
	int n;
	cout<<"enter no. of task\n";
	cin>>n;
	TASK task[n];
	cout<<"enter release time, computation time,time period,deadline of each task\n";
	
	for(int i=0;i<n;i++){
		cin>>task[i].rt>>task[i].ct>>task[i].tp>>task[i].dl;
		task[i].k=0;//it is used to initialize k value 
	}

	//to calculate hyper period
	int hyperPeriod=task[0].tp;

	for(int i=0;i<n-1;i++){
		hyperPeriod=(hyperPeriod*task[i+1].tp)/(__gcd(hyperPeriod,task[i].tp));
	}
	// cout<<hyperPeriod;

	for(int i=0;i<n;i++){
		int jobTimePeriod=task[i].rt,j=0;

        //calculating relative deadline of each job with its absolute deadline
		while(jobTimePeriod<hyperPeriod){
			task[i].rtime[j]=j*task[i].tp;
			task[i].adl[j]=task[i].rtime[j]+task[i].dl;
			j++;
			jobTimePeriod=j*task[i].tp;
		}
		task[i].noOfjob=j;
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<task[i].noOfjob;j++){
	// 		cout<<task[i].rdl[j]<<"\t"<<task[i].adl[j]<<"\t";
	// 	}
	// 	cout<<"\n";
	// }

	// calculating frame size

	int minFrameSize=INT_MIN//>=max(coputationTime)
	,maxFrameSize=INT_MAX//<=minimumOfTimePeriod
	,frameSize;

   //minFrameSize is the maxComputation time
   //maxFrameSize is the minDeadline
	for(int i=0;i<n;i++){
		minFrameSize=max(task[i].ct,minFrameSize);
	}
		for(int i=0;i<n;i++){
		maxFrameSize=min(task[i].tp,maxFrameSize);
	}
	//cout<<minFrameSize<<"\t"<<maxFrameSize;
	int j=0;
    //cout<<hyperPeriod;
	for(int i=2;i<hyperPeriod;i++){
		if(hyperPeriod%i==0){
		   // cout<<"i"<<i<<"\n";
			if(i>=minFrameSize && i<=maxFrameSize)
			{
			   for(j=0;j<n;j++)
			   {
			      //cout<<"j"<<j<<"\n";
			      if(2*i-__gcd(task[j].tp,i)>task[j].dl)
			      {
			         break;
			      }
			   }
			   if(j==n)
			   {
			     //cout<<"inside";
			     frameSize=i;
			     break;
			   }
		   }
		}
	}
	cout<<"FrameSize= "<<frameSize<<"\n";
	
	int k=0,mini=INT_MAX,jvalue,remainFrame,i;
	
	for(i=0;i<=hyperPeriod;i++)
	{
	   if(i%frameSize==0)
	   {
	      remainFrame=frameSize;
	      while(remainFrame>0)
	      {
	          mini=INT_MAX;
	          for(j=0;j<n;j++)
	          {
                 if(task[j].k<task[j].noOfjob && task[j].adl[task[j].k]<mini && task[j].rtime[task[j].k]<=i)
                 {
                   mini=task[j].adl[task[j].k];
                   jvalue=j;
                   // cout<<"j "<<jvalue<<"k= "<<task[jvalue].k<<" "<<"mini  "<<mini<<" ";
                 }
	          }
	          // cout<<"RemainFrame= "<<remainFrame<<"jvalue= "<<jvalue<<"\n";
	          if(task[jvalue].ct<=remainFrame && task[jvalue].k<task[jvalue].noOfjob)
	          {
	          
	             task[jvalue].k++;
	           /*  cout<<"RemainFrame= "<<remainFrame<<"\n";
	             cout<<"jvalue= "<<jvalue<<"\n";
	             cout<<"Kvalue= "<<task[jvalue].k<<"\n";*/
	             cout<<"T"<<jvalue+1<<task[jvalue].k<<" ";
	             remainFrame=remainFrame-task[jvalue].ct;
	          }
	          else
	          {
	             break;
	          }

	      }
	      cout<<"   ";
	      
	   } 
	} 
}