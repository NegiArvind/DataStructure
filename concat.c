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
NODE *concat(NODE *,NODE *);
void display(NODE *);
void main()
{
  int x,n,y; 
  NODE *head1=NULL,*head2=NULL,*head3=NULL;
  while(1)
  {
     printf("enter your choice\n 1-insert an element \n 2-concating lists \n 3-display all elements of list\n 4-exit\n");
     scanf("%d",&x);
     switch(x)
     {
       case 1:
       printf("in which list you want to insert element--in list 1 or list 2\n");
       scanf("%d",&y);
       if(y==1)
       {
         printf("enter the element\n");
         scanf("%d",&n);
         head1=insert_end(head1,n);
        }
        if(y==2)
        {
          printf("enter the  element\n");
          scanf("%d",&n);
          head2=insert_end(head2,n);
        }
        else
        printf("you entered wrong choice\n");
        break;
        
        case 2:
        printf("after concatination two list\n");
        head3=concat(head1,head2);
        break;
        
        case 3:
        display(head3);
        break;
        
        case 4:
        exit(1);
        break;
        
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
NODE *concat(NODE *head1,NODE *head2)
{
  NODE *p=head1,*q=head2;
  if(head1==NULL)
  {
    return(head2);
   }
  else if(head1==NULL&&head2==NULL)
       {
         printf("no concatination can occur\n");
         return(NULL);
        }
  else
  {
    while(p->next!=NULL)
    p=p->next;
    p->next=q;  
    return(head1);
  }
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

  
         
  
