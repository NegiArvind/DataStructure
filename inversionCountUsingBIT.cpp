#include<bits/stdc++.h>
using namespace std;
long f[1000001];
long getSum(long bit[],long index)
{
    long sum=0;
    while(index>0)
    {
        sum+=bit[index];
        index-=(index&-index); //parent of index
    }
    return sum;
}

void updatebit(long bit[],long n,long index,long value)
{
    while(index<=n)
    {
        bit[index]+=value;
        index+=(index&-index);
    }
}

void convert(long a[],long n)
{
    long temp[n],i;
    for(i=0;i<n;i++)
    temp[i]=a[i];
    sort(temp,temp+n);
    for(i=0;i<n;i++)
    {
        a[i]=lower_bound(temp,temp+n,a[i])-temp+1;
        a[i]=n+1-a[i];
    }
}

void invCount(long a[],long n)
{
    convert(a,n); 
    long bit[n+1];
    for(long i=0;i<=n;i++)
    bit[i]=0;
    // memset(bit,0,sizeof(bit));
    for(int i=n-1;i>=0;i--)
    {
        f[i]=getSum(bit,a[i]-1);
        updatebit(bit,n,a[i],1);
    }
}

int main()
{
    long n,k,x,i,j;
    cin>>n>>k;
    long a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    invCount(a,n);
    sort(f,f+n);
    // for(i=0;i<n;i++)
    // cout<<f[i]<<" ";
    
    long long count=0;
    vector<int>v(f,f+n);
	for(long i=n-1;i>=0;i--)
	{
		int j=lower_bound(v.begin(),v.end(),k-v[i])-v.begin(); //binary search
		if(j!=n && j<i)
			count+=i-j;
	}
	printf("%lld\n",count);
}