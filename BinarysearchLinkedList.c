#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node NODE;
NODE *insert(NODE *,int);
NODE *getnode();
void display(NODE *);
NODE *middle(NODE *,NODE *);
NODE *binarySearch(NODE *,int x);
void main()
{
   int n,x;
    NODE *head=NULL,*element;
    printf("Enter the elements in linked list(press -1 for terminating)\n");
    while(1)
    {
      scanf("%d",&n);
      if(n==-1)
      break;
      head=insert(head,n);
    }
    display(head);
    printf("Enter the element to be searched\n");
    scanf("%d",&x);
    element=binarySearch(head,x);
    cout<<element->info;
}
NODE *getnode()
{
   return ((NODE *)malloc(sizeof(NODE)));
}

NODE *insert(NODE *head,int key)
{
    NODE *p=head,*q;
    q=getnode();
    q->info=key;
    q->next=NULL;
    if(p==NULL)
    {
        head=q;
        return  head;
    }
    else
    {
        while(p->next!=NULL)
        {
           p=p->next;
        }
        p->next=q;
        return head;
    }
}
NODE *middle(NODE *startNode,NODE *endNode)
{
    if(startNode==NULL)
    return;
    
   NODE *slowPtr=startNode;
   NODE *fastPtr=startNode;
   
   while(fastptr!=endNode)
   {
      fastptr=fastptr->next;
      if( fastPtr != endNode ) 
      { 
            slowPtr = slowPtr -> next ;     
            fastPtr = fastPtr -> next ;       
      }
   }
   return slowPtr;
}

NODE *binarySearch(NODE *head,int x)
{
     NODE *startnode=head;
     NODE *endNode=NULL;
     do
     {
         NODE *middle=middle(startNode,endNode);
         if(middle==NULL)
         {
             printf("Searched Element no present\n");
             return NULL;
         }
         else if(middle->info==x)
         {
            return middle;
         }
         else if(middle->info < x)
         {
             startnode=middle->next;
         }
         else if(middle->info > x)
         {
              endNode=middle;
         }
     }while(endNode==NULL||endNode->next!=startNode);
     return NULL;
}
void display(NODE *head)
{
   NODE *p=head;
   while(p!=NULL)
   {
      printf("%d->",p->info);
      p=p->next;
   }
}

