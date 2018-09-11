#include<stdio.h>
#include<malloc.h>
void max_heapify(int i,int n,int a[]);
void make_max_heap(int ,int a[]);
void heap_sort(int ,int a[]);
void swap(int *,int *);
void main()
{
   int a[30],i=0,j,n;
   printf("enter elements which you want to insert(-1 for termination)\n");
   while(1)
   {
      scanf("%d",&n);
      if(n==-1)
      break;
      a[i++]=n;
   }
     
   make_max_heap(i,a);
   printf("Elements in Max heap Array\n");
   for(j=0;j<i;j++)
   {
      printf("%d\t",a[j]);
   }
   printf("\n");
   heap_sort(i,a);
   printf("Sorted array\n");
   for(j=0;j<i;j++)
   {
      printf("%d\t",a[j]);
   }
   printf("\n");
}
void make_max_heap(int k,int b[])
{
  int i; 
  for(i=k/2;i>0;i--)
  {
     max_heapify(i,k,b);
  }
}
void max_heapify(int i,int n,int a[])
{
  int l,r,largest=i,temp;
  l=2*i;
  r=2*i+1;
  if(l<=n && a[i]<a[l])
  {
     largest =l;
  }
  if(r<=n && a[largest]<a[r])
  {
    largest=r;
  }
  if(largest!=i)
  {
     swap(&a[i],&a[largest]);
     //temp=a[i];
     //a[i]=a[largest];
     //a[largest]=temp;
     max_heapify(largest,n,a);
     
  }
}
void heap_sort(int n,int b[])
{
  int i;
  for(i=n;i>0;i--)
  {
    swap(&b[1],&b[i]);
    max_heapify(1,n-1,b);
  }
}
void swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

