//program to merge an array which is not sorted using mergesort
#include<stdio.h>
void merge_sort(int a[],int,int);
void merge(int b[],int,int,int);
int i,j;
void main()
{
  int a[20],n;
  printf("enter no. of elements of array\n");
  scanf("%d",&n);
  printf("enter elements of the array\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  merge_sort(a,0,n-1);
  printf("after sorting\n");
  for(i=0;i<n;i++)
  printf("%d\n",a[i]);
}
void merge_sort(int c[],int p,int r)
{
  int q;
  //divide array into sub parts
  if(p<r)
  {
    q=(p+r)/2; 
    merge_sort(c,p,q);
    merge_sort(c,q+1,r);
    merge(c,p,q,r);
  }
}
void merge(int t[],int a,int b,int c)
{
  int n1,n2,k[c-a+1];
  n1=b-a+1;
  n2=c-a;
  int d[n1+1],e[n2+1];
  //store two sorted array in two different array
  for(i=0;i<n1;i++)
  d[i]=t[i];
  for(j=0;j<n2;j++)
  {
   e[j]=t[i];
   i++;
  }
  d[n1+1]=3278;
  e[n2+1]=3247;
  //merging two different array in one array
  for(i=0;i<c;i++)
  {
    if(d[i]<e[i])
    k[i]=d[i];
    else
    k[i]=e[i];
  }
  for(i=0;i<c-a+1;i++)
  t[i]=k[i];  
}
  
