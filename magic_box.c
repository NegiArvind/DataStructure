#include<stdio.h>
void main()
{
  int a[20][20],i=0,j,m,n=1;
  int s,t;
  printf("enter the size of the array\n");
  scanf("%d",&m);
  j=m/2;
  while(n<=m*m)
  {
    if(i<0)
    i=m-1;
    if(j<0)
    j=m-1;
    a[i][j]=n;
    if(n%m==0)
    {
      i=i+2;
      j=j+1;
    }
    i--;
    j--;
    n++;
  }
  //print digit in array and add all row elements
  for(i=0;i<m;i++)
  { 
    s=0;
    for(j=0;j<m;j++)
    {
      printf("%d\t",a[i][j]);
      s=s+a[i][j];
    }
    printf("%d\t",s);
    printf("\n");
  }
  //add all column elements
  for(j=0;j<m;j++)
  {
    t=0;
    for(i=0;i<m;i++)
    {
      t=t+a[i][j];
    }
    printf("%d\t",t);
  }
  printf("\n");
}
 
