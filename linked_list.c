#include<stdio.h>

#include<stdlib.h>

struct node

{

  int info;

  struct node *next;

};

typedef struct node NODE;

NODE *getnode();

NODE *insert_start(NODE *,int);

NODE *insert_end(NODE *,int);

NODE *insert_anywhere(NODE *,int,int);

NODE *delete_start(NODE *);

NODE *delete_end(NODE *);

NODE *delete_anywhere(NODE *,int);

void display(NODE *);

void main()

{

   NODE *head=NULL;

   int x,m,n;

   while(1)

   {

	   printf("Enter your choice\n 1-insertion at start\n 2-insertion at end \n 3-insertion at anywhere\n 4-deletion at start \n 5-deletion at end \n 6-deletion at anywhere\n 7-displaying all the element in a list\n 8-exit\n");

       scanf("%d",&x);

	   switch(x)

	   {

		   case 1:

		   printf("enter the element\n");

		   scanf("%d",&m);

		   head=insert_start(head,m);

		   break;

		   

		   case 2:

		   printf("enter the element\n");

		   scanf("%d",&m);

		   head=insert_end(head,m);

		   break;

		    

		   case 3:

		   printf("enter the element\n");

		   scanf("%d",&m);

		   printf("enter the element after which you have to insert\n");

		   scanf("%d",&n);

		   head=insert_anywhere(head,m,n);

		   break;

		   

		   case 4:

		   printf("now you are going to delete one element\n");

           head=delete_start(head);

		   break;

		   

		   case 5:

		   printf("now you are going to delete one element\n");

		   head=delete_end(head);

		   break;

		   

		   case 6:

		   printf("now you are going to delete one element\n");

		   printf("enter the element which you have to delete\n");

		   scanf("%d",&n);

		   head=delete_anywhere(head,n);

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

   }

}

NODE *getnode()

{

	return((NODE *)malloc(sizeof(NODE)));

}

NODE *insert_start(NODE *head,int key)

{

	NODE *p;

	p=getnode();

	p->info=key;

	p->next=head;

	head=p;

	return(head);

}

NODE *insert_end(NODE *head,int key)

{

	NODE *p=head,*q;

	q=getnode();

	q->info=key;

	q->next=NULL;

	if(head==NULL)

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

NODE *insert_anywhere(NODE *head,int key,int x)

{

	NODE *p=head,*q;

	q=getnode();

	q->info=key;

	if(x<0)

	{

		q->next=head;

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

		    	p->next=q;

			    break;

		    }

		    p=p->next;

	  }

	  if(p==NULL)

	  printf("element not matched\n");

      return(head); 

	}

}

NODE *delete_start(NODE *head)

{

	NODE *p=head;

	if(p==NULL)

	printf("underflow");

    else

    {

		head=p->next;

	    free(p);

	    return(head);

	}

}

NODE *delete_end(NODE *head)

{

	NODE *p=head,*q;

	if(head==NULL)

	{

		printf("underflow\n");

        return(head);

	}

	if(head->next==NULL)

	{

		head=head->next;

		free(head);

		return(head);

	}

	else

	{

	  while(p->next!=NULL)

	  {

	    	q=p;

	    	p=p->next;

	  }

	  q->next=p->next;

	  free(p);

	  return(head);

	}

}

NODE *delete_anywhere(NODE *head,int x)

{

	NODE *p=head,*q;

	if(head->info==x)

	{

		head=NULL;

		free(head);

		return(head);

	}

	else

	{

	  while(p!=NULL)

	  {

	    	if(p->info==x)

	    	{

	    		q->next=p->next;

	    		free(p);

		    	break;

            }

	     	q=p;

		    p=p->next;

	  }

	  return(head);

    }

	

}

void display(NODE *head)

{

	NODE *p=head;

	printf("All elements\n");

	while(p!=NULL)

	{

      printf("%d\t",p->info);

	  p=p->next;

	}

}


