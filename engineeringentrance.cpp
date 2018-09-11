#include<iostream>
using namespace std;

int main()
{
  long m,n,p,k,i,j,q,w,u,v;
  long min,home;
  cin>>n>>m>>k>>q;
  long c[n+1][n+1],b[k];
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
        if(i==j)
        c[i][j]=0;
        else
        c[i][j]=1000000001;
     }
  }
  for(i=1;i<=m;i++)
  {
        cout<<"hel";
        cin>>u>>v>>w;
        c[i][j]=w;
        c[j][i]=w;
     
  }
  for(i=0;i<k;i++)
  {
    cin>>b[i];
  }
  for(p=1;p<=n;p++)
  {
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           if(c[i][j]>(c[i][k]+c[k][j]))
           c[i][j]=c[i][k]+c[k][j];
       }
    }
  }
  for(i=0;i<q;i++)
  {
    cin>>home;  
    for(j=0;j<k-1;j++)
    { 
      if(home==b[j])
      {
        min=home;
      }
      else
      {
        min=c[home][b[j]];
        if(c[home][b[j]]>=1000000001)
        {
          min=-1;
          break;
        }
        if(min>c[home][b[j+1]])
        min=c[home][b[j+1]];
     }
   }
   cout<<min<<"\n";
  }
}

