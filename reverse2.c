#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node NODE;
NODE *getnode();
NODE *insert_end(NODE *,int);
NODE *reverse(NODE *);
void display(NODE *);
void main()
{
  int x,n;
  NODE *head=NULL;
  while(1)
  {
    printf("enter your choice\n 1-inserting element \n 2-reversing list \n 3-display all elements \n 4-exit\n");
    scanf("%d",&x);
    switch(x)
    {
      case 1:
      printf("enter the elements\n");
      scanf("%d",&n);
      head=insert_end(head,n);
      break;
      
      case 2:
      printf("now you are going to reverse the list\n");
      head=reverse(head);
      break;
      
      case 3:
      display(head);
      break;
      
      case 4:
      exit(1);
      
      default:
      printf("you entered wrong choice\n");
    }
   }
}
NODE *getnode()
{
 return((NODE *)malloc(sizeof(NODE)));
}

NODE *insert_end(NODE *head,int key)
{
  NODE *p=head,*q;
  q=getnode();
  q->info=key;
  if(head==NULL)
  {
     q->next=NULL;
     head=q;
     return(head);
   }
   else
   {
     while(p->next!=NULL)
     p=p->next;
     p->next=q;
     q->next=NULL;
     return(head);
   }
}

NODE *reverse(NODE *head)
{
  NODE *p=NULL,*q=head,*r;
  while(q!=NULL)
  {
     r=q->next;
     q->next=p;
     p=q;
     q=r;
  }
  head=p;
  return(head);
}

void display(NODE *head)
{
  NODE *p=head;
  while(p!=NULL)
  {
    printf("%d\t",p->info);
    p=p->next;
   }
   printf("\n");
}

   
     
