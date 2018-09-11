//c program for multilinked representation of sparse matrix
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct mlnode
{
  int row,col,val;
  struct mlnode *nextrow,*nextcolumn;
};
typedef struct mlnode MLNODE;
MLNODE *delete_column(MLNODE *,int);
MLNODE *getnode();
MLNODE *getmlmatrix(MLNODE *,int ,int);
MLNODE *insert(MLNODE *,int,int,int);
MLNODE *delete_row(MLNODE *,int );
MLNODE *above(MLNODE *,int,int);
MLNODE *left(MLNODE *,int,int);
MLNODE *triplet_represent(MLNODE *);
void linktomatrix(MLNODE *);
void main()
{
   MLNODE *head=NULL;
   int m,n,a1,b;
   int x,i,j;
   printf("Enter the no. of rows and column\n");
   scanf("%d %d",&m,&n);
   int a[m][n];
   head=getmlmatrix(head,m,n);
   printf("enter the element\n");
         for(i=0;i<m;i++)
         {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
         }
         //head=getmlmatrix(head,m,n);
       // head=getmlmatrix(head,m,n);
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
               if(a[i][j]!=0)
               head=insert(head,i,j,a[i][j]);
             }
          }
   while(1)
   {
      printf("Press these numbers \n1-triplet representation \n2-deleting a row"
    
               "\n3-deleting a column \n4-exit\n");
      scanf("%d",&x);
      switch(x)
      {
        /* case 1:{
         //printf("Enter the no. of rows and column\n");
         //scanf("%d %d",&m,&n);
        // int a[m][n];
         printf("enter the element\n");
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
         }
         //head=getmlmatrix(head,m,n);
         printf("hello");
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
               if(a[i][j]!=0)
               head=insert(head,i,j,a[i][j]);
             }
          }
          break;}
         */
          case 1:
          printf("Triplet representation of this sparse matrix");
          head=triplet_represent(head);
          //display(head);
          break;
 
         /* case 3:
          display(head);
          break;*/

          case 2:
          printf("Enter the row which you want to delete in linked representation(start from 0)\n");
          scanf("%d",&a1);
          head=delete_row(head,a1);
          printf("After deleting the triplet representation is:\n");
          head=triplet_represent(head); 
          //display(head);
          printf("In matrix form:\n");
          linktomatrix(head); 
          break;

          case 3:
          printf("Enter the column which you want to delete in linked representation(start from 0)\n");
          scanf("%d",&b);
          head=delete_row(head,b);
          printf("After deleting the triplet representation is:\n");
          head=triplet_represent(head);  
          printf("In matrix form:\n");
          linktomatrix(head); 
          break;

          case 4:
          exit(1);
          break;

          default:
          printf("You entered wrong choice\n");
      }
   }
}

MLNODE *getnode()
{
   return((MLNODE *)malloc(sizeof(MLNODE)));
}

MLNODE *getmlmatrix(MLNODE *head,int m,int n)
{
   MLNODE *q,*p;
   int k=0;
   q=getnode();
   q->row=-1;
   q->col=-1;
  // q->nextcolumn=q;
  // printf("hi");
  // q->nextrow=q;
   head=q;
  //make a column header node
   while(k<n)
   {
       p=getnode();
       p->row=-1;
       p->col=k;
       p->nextrow=p;
       p->nextcolumn=q;
       //q->nextcolumn=p;
       k++;
       q=p;
   }
   //make a row header node
   k=0;
   while(k<m)
   {
       p=getnode();
       p->col=-1;
       p->row=k;
       p->nextcolumn=p;
       p->nextrow=q;
       k++;
       q=p;
   }
   return(head);
}

MLNODE *insert(MLNODE *head,int r,int c,int v)
{

   MLNODE *s,*p,*q;
   s=getnode();
   s->row=r;
   s->col=c;
   p=above(head,r,c);
   q=left(head,r,c);
   s->nextcolumn=q->nextcolumn;
   q->nextcolumn=s;
   s->nextrow=q->nextrow;
   q->nextrow=s;
   return(head);
}
   
MLNODE *triplet_represent(MLNODE *head)
{
  MLNODE *p=head->nextrow;
  printf(" Row  Column  Value\n");
  while(p->nextrow!=p)
  {
     p=p->nextcolumn;
     while(p->col!=-1)
    {
       printf("%d\t %d\t %d\t ",p->row,p->col,p->val);
       p=p->nextcolumn;
    }
    p=p->nextrow;
  }
  return(p);
}

void linktomatrix(MLNODE *head)
{
   MLNODE *p=head->nextcolumn,*q;
   int m=0,n=0;
   //calculating the no. of row and column of that matrix
   while(p->col!=-1)
   {
      n++;
      p=p->nextcolumn;
   }
   p=head->nextrow;
   while(p->row!=-1)
   {
      m++;
      p=p->nextrow;
   }
   int a[m][n];
   p=p->nextrow;
   q=p;
   memset(a,0,sizeof(a));//this is a function inside of string header file which is used to put 0 in whole matrix
   while(p->nextrow!=head)
   {
      while(p->nextcolumn!=q)
      {
          a[p->row][p->col]=p->val;
          p=p->nextcolumn;
      }
          p=p->nextrow;
          q=p;
    }
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
         printf("%d\t",a[i][j]);  
      }
      printf("\n");
    }
}
  
MLNODE *delete_row(MLNODE *head,int r)
{
    MLNODE *q=head,*p=head->nextrow,*x,*p1,*q1;
    while(p->row!=r)
    {
       q=p;
       p=p->nextrow;
       x=p;
    }
    while(p->nextcolumn!=x)
    {
       p=p->nextcolumn;
       p1=above(head,p->row,p->col);
       q1=left(head,p->row,p->col);
       p1->nextrow=p->nextrow;
       q1->nextcolumn=p->nextcolumn;
       free(p);
       p=q1->nextcolumn; 
    }
    q->nextrow=p->nextrow;
    free(p);
    p=q->nextrow;
    while(q->nextrow!=head)
    {
       x=p;
       x->row--;
       while(p->nextcolumn!=x)
       {
          p=p->nextcolumn;
          p->row--;
       }
       p=p->nextrow;
       q=q->nextrow;
    }
  return(head);
}

MLNODE *delete_column(MLNODE *head,int c)
{
    MLNODE *q=head,*p=head->nextcolumn,*x,*p1,*q1;
    while(p->col!=c)
    {
       q=p;
       p=p->nextcolumn;
       x=p;
    }
    while(p->nextrow!=x)
    {
       p=p->nextrow;
       p1=above(head,p->row,p->col);;
       q1=left(head,p->row,p->col);
       p1->nextcolumn=p->nextcolumn;
       q1->nextrow=p->nextrow;
       free(p);
       p=q1->nextrow; 
    }
    q->nextcolumn=p->nextcolumn;
    free(p);
    p=q->nextcolumn;
    while(q->nextcolumn!=head)
    {
       x=p;
       x->col--;
       while(p->nextrow!=x)
       {
          p=p->nextrow;
          p->col--;
       }
       p=p->nextcolumn;
       q=q->nextcolumn;
    }
  return(head);
}

MLNODE *above(MLNODE *head,int r,int c)
{
   MLNODE *p=head->nextcolumn,*q;
   while(p->col<c&&p->col!=-1)
   {
     p=p->nextcolumn;
   } 
   p=p->nextrow;
   while(p->row<r&&p->row!=-1)
   {
     q=p;
     p=p->nextrow;
   }
   return(q);
}    

MLNODE *left(MLNODE *head,int r,int c)
{
   MLNODE *p=head->nextrow,*q;
   while(p->row<r && p->row!=-1)
   {
     p=p->nextrow;
   } 
   p=p->nextcolumn;
   while(p->col<c && p->col!=-1)
   {
     q=p;
     p=p->nextcolumn;
   }
   return(q);
}      

  
   

          











