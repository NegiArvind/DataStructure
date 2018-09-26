#include<bits/stdc++.h>
using namespace std;
struct task{
    int rt,ct,tp,dl;
    bool check;
};
typedef struct task TASK;
bool compare(TASK t1,TASK t2)
{
    return t1.tp<t2.tp;
}
int main(){
    int n,i,j;
    cout<<"enter no. of task\n";
    cin>>n;
    TASK task[n];
    cout<<"enter release time, computation time,time period,deadline of each task\n";
    for(int i=0;i<n;i++){
        cin>>task[i].rt>>task[i].ct>>task[i].tp>>task[i].dl;
    }
    
    //InExact schedulability test
    float combUtilization,thresUtilization;
    for(int i=0;i<n;i++)
    {
    	combUtilization+=(float)task[i].ct/task[i].tp;
    }
    thresUtilization=n*(float(pow(2.0,(float)1/n))-1);
    cout<<"Threshold Utilization=  "<<thresUtilization<<"\n";
    cout<<"Combination Utilization=  "<<combUtilization<<"\n";
    cout<<"Inexact schedulability Test Result : \n";
    if(combUtilization<=thresUtilization)
    {
    	cout<<"Task set can be schedulable according inexact schedulability test\n";
    }else{
    	cout<<"Task set can not be schedulable according inexact schedulability test\n";
    }

    //exact schedulability test
    cout<<"Exact Scheduling : \n";
    cout<<"Scheduling based on RM algorithm\n";
    sort(task,task+n,compare);
    // for(i=0;i<n;i++)
    // {
    //     cout<<task[i].tp<<" ";
    // }
    float wb1,wb;
    for(i=0;i<n;i++)
    {
        //cout<<"hello";
        if(i!=0)
        {
            //cout<<"pagal";
            wb=task[i].ct;
            while(1)
            {
                //cout<<"hi";
                wb1=task[i].ct;
                for(j=0;j<i;j++)
                {
                    wb1+=ceil((float)wb/task[j].tp)*task[j].ct;
                }

                cout<<"wb1= "<<wb1<<"\n";
                if(wb==wb1 && wb1<=task[i].tp)
                {
                    task[i].check=true;
                    break;
                }
                else if(wb1>task[i].tp)
                {
                    break;
                }
                wb=wb1;
            }
        }
        else
        {
            task[i].check=true;
        }
    }
    for(i=0;i<n;i++)
    {
        if(task[i].check==false)
        {
            cout<<"Task can not be schedule according exact schedulability test\n";
            break;
        }
    }
    if(i==n)
        cout<<"Task can be schedule according exact schedulability test\n";
}
