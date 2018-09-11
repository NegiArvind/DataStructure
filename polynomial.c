#include<stdio.h>
#include<stdlib.h>
struct node
{
  int exp,coeff;
  struct node *next;
};
typedef struct node NODE;
NODE *getnode();
NODE *insert_end(NODE *,int,int);
NODE *addition(NODE *,NODE *);
void display(NODE *);
void main()
{
  int m,n,y;
  NODE *head1=NULL,*head2=NULL,*head3;
  while(1)
  {
    printf("enter the equations 1 or 2(0 for terminating)\n");
    scanf("%d",&y);
    if(y==1)
    {
       printf("enter the coefficient and exponents in decreasing order(0 and 0 is termination condition)\n");
       while(1)
       {
         scanf("%d %d",&m,&n);
         if(m==0&&n==0)
         break;
         else
         head1=insert_end(head1,m,n);
       }
       display(head1);
     }
    else if(y==2)
       {
          printf("enter the coefficient and exponents in decreasing order(0 and 0 is termination condition)\n");
          while(1)
          {
             scanf("%d %d",&m,&n);
             if(m==0&&n==0)
             break;
             else
             head2=insert_end(head2,m,n);
           }
         display(head2);
        }
        else 
        break;
   }
   printf("after addition two equation :\n");
   head3=addition(head1,head2);
   display(head3);
}

NODE *getnode()
{
   return((NODE *)malloc(sizeof(NODE)));
}
NODE *insert_end(NODE *head,int a ,int b)
{
   NODE *p=head,*q;
   q=getnode();
   q->coeff=a;
   q->exp=b;
   q->next=NULL;
   if(p==NULL)
   {
     head=q;
     return(head);
   }
   else
   {
     while(p->next!=NULL)
     p=p->next;
     p->next=q;
     return(head);
    }
}

NODE *addition(NODE *head1,NODE *head2)
{
  int coeff;
  NODE *p=head1,*q=head2,*head3=NULL;
  //NODE *r=head3;
  while(p!=NULL&&q!=NULL)
  {
    if(p->exp>q->exp)
    {
      head3=insert_end(head3,p->coeff,p->exp);
      p=p->next;
    }
    else if(p->exp<q->exp)
         {
            head3=insert_end(head3,q->coeff,q->exp);
            q=q->next;
         }
       else
       {
         coeff=p->coeff+q->coeff;
         if(coeff!=0)
         {
           head3=insert_end(head3,coeff,p->exp);
           p=p->next;
           q=q->next;
         }
       }
   }
   while(p!=NULL)
   head3=insert_end(head1,p->coeff,p->exp);
   while(q!=NULL)
   head3=insert_end(head1,q->coeff,q->exp);
   return(head3);
}
void display(NODE *head)
{
  NODE *p=head;
  while(p!=NULL)
  {
    printf("%d-->%d\t",p->coeff,p->exp);
    p=p->next;
   }
}




