//c program for doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next,*prev;
};
typedef struct node NODE;
NODE *getnode();
NODE *insert_start(NODE *,int);
NODE *insert_end(NODE *,int);
NODE *insert_anywhere(NODE *,int ,int);
NODE *delete_start(NODE *);
NODE *delete_end(NODE *);
NODE *delete_anywhere(NODE *,int);
void display(NODE *);
void main()
{
  int x,n,m,d;
  NODE *head=NULL;
  do
  {
    printf("Enter your choice\n 1-insert at start \n 2-insert at end \n 3-insert at anywhere \n 4-delete at start \n 5-delete at end\n"); 
    printf(" 6-delete  anywhere \n 7-display the list \n 8 exit\n");
    scanf("%d",&x);
    switch(x)
    {
       case 1:
       printf("enter the element\n");
       scanf("%d",&n);
       head=insert_start(head,n);
       break;
    
       case 2:
       printf("enter the elements\n");
       scanf("%d",&n);
       head=insert_end(head,n);
       break;

       case 3:
       printf("enter the elements\n");
       scanf("%d",&n);
       printf("enter the element after which you have to insert element\n");
       scanf("%d",&m);
       head=insert_anywhere(head,n,m);
       break;
  
       case 4:
       printf("now you are deleting the element\n");
       head=delete_start(head);
       break;
   
       case 5:
       printf("now you are deleting the element\n");
       head=delete_end(head);
       break;
   
       case 6:
       printf("now you are deleting the element\n");
       printf("enter the element which you have to delete\n");
       scanf("%d",&d);
       head=delete_anywhere(head,d);
       break;

       case 7:
       display(head);
       break;
 
       case 8:
       exit(1);
       break;
 
       default:
       printf("you entered wrong choice\n");
     }
  }while(1);
}

NODE *getnode()
{
  return((NODE *)malloc(sizeof(NODE)));
}

NODE *insert_start(NODE *head,int key)
{
  NODE *p=head,*q;
  q=getnode();
  q->info=key;
  q->prev=NULL;
  if(head==NULL)
  {
    q->next=NULL;
    head=q;
    return(head);
  }
  else
  {
    q->next=p;
    head=q;
    return(head);
  }
}

NODE *insert_end(NODE *head,int key)
{
  NODE *p=head,*q;
  q=getnode();
  q->info=key;
  if(head==NULL)
  {
    q->prev=NULL;
    q->next=NULL;
    head=q;
    return(head);
  }
  else
  {
    while(p->next!=NULL)
    p=p->next;
    q->prev=p;
    p->next=q;
    q->next=NULL;
    return(head);
  }
}
NODE *insert_anywhere(NODE *head,int key,int x)
{
  NODE *p=head,*q;
  q=getnode();
  q->info=key;
  if(head==NULL)
  {
    //printf("there is no element so you can not insert\n");
    q->prev=NULL;
    q->next=NULL;
    head=q;
    return(head);
  }  
  else
  {
    while(p!=NULL)
    {
      if(p->info==x)
      {
        q->next=p->next;
        q->prev=p;
        p->next=q;
        break;
      }
      p=p->next;
    }
    if(p==NULL)
    printf("element not matched which you entered\n");
    return(head);
  }
}

NODE *delete_start(NODE *head)
{
  NODE *p=head;
  if(head==NULL)
  {
    printf("underflow\n");
    return(head);
  }
  else if(p->next==NULL)
      {
        head=p->next;
        free(p);
        return(head);
      }
  else
  {
    head=p->next;
    p->next->prev=NULL;
    free(p);
    return(head);
  }
}

NODE *delete_end(NODE *head)
{
  NODE *p=head;
  if(head==NULL)
  {
    printf("underflow\n");
    return(head);
  }
  else if(p->next==NULL)
       {
         head=p->next;
         free(p);
         return(head);
       }
  else
  {
    while(p->next!=NULL)
    p=p->next;
    p->prev->next=NULL;
    free(p);
    return(head);
  }
}

NODE *delete_anywhere(NODE *head,int key)
{
  NODE *p=head;
  if(head==NULL)
  {
   printf("underflow\n");
   return(head);
  }
  else if(p->next==NULL&&p->prev==NULL&&p->info==key)
       {
          head=NULL;
          free(p);
          return(head);
       }
    else if(p->next==NULL&&p->prev==NULL&&p->info!=key)
         {
            printf("element not matched\n");
            return(head);
         }
    
    else
    {
      while(p!=NULL)
      {
        if(p->info==key)
        {
          p->next->prev=p->prev;
          p->prev->next=p->next;
          free(p);
          break;
        }
      }
      if(p==NULL)
      printf("element not matched\n");
      return(head);
    }
}

void display(NODE *head)
{
  NODE *p=head;
  printf("elements are:\n");
  while(p!=NULL)
  {
     printf("%d\t",p->info);
     p=p->next;
  }
}       
