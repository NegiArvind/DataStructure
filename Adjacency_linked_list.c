#include<stdio.h>
#include<malloc.h>
struct node
{
  char info;
  struct node *next;
};
typedef struct node NODE;
NODE *getnode();
NODE *insert(NODE *,char);
void display(NODE *a[],int);
void main()
{
  int n;
  char c;
  char ch[20];
  printf("Enter the no. vertics\n");
  scanf("%d",&n);
  NODE *a[n];
  //char ch[n];
  printf("Enter vertices\n");
  for(int i=0;i<n;i++)
  {
     scanf(" %c",&ch[i]);
     a[i]=getnode();
     a[i]->next=NULL;
     a[i]->info=ch[i];
  }
  for(int i=0;i<n;i++)
  {
     for(int j=i;j<n;j++)
     {
       if(i==j)
       continue;
      
           printf("Is %c is connected to %c(y/n) ",ch[i],ch[j]);
           scanf(" %c",&c);
           if(c=='y')
           {
              a[i]=insert(a[i],ch[j]);
              a[j]=insert(a[j],ch[i]);
           }
     }
   }
   printf("Adjacency linked list representation\n");
   display(a,n);
}
NODE *getnode()
{
  return((NODE *)malloc(sizeof(NODE)));
}
NODE *insert(NODE *head,char ch)
{
   NODE *p=head,*q;
   if(head==NULL)
   return(NULL);
   while(p->next!=NULL)
   {
     p=p->next;
   }
   q=getnode();
   q->info=ch;
   q->next=NULL;
   p->next=q;
   return(head);
}

void display(NODE *a[],int m)
{
  int i=0;
  NODE *p;
  printf("Vertices       Adjacent Vertices\n");
  for(i=0;i<m;i++)
  {
     printf(" %c\t\t",a[i]->info);
     p=a[i]->next;
  while(p!=NULL)
  {
      printf("%c  ",p->info);
      p=p->next;
  }
  printf("\n");
 }
}





