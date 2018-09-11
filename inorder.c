//finding inorder traversal of a tree using stack
#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
struct tree
{
  int info;
  struct tree *lchild,*rchild;
};
typedef struct tree TREE;
struct stack
{
  int top;
  TREE *a[STACKSIZE];
};
typedef struct stack STACK;
STACK s;
void push(TREE *);
TREE *pop();
TREE *getnode();
TREE *inorder(TREE *);
TREE *maketree(TREE *,int);
void main()
{
   s.top=-1;
   TREE *root=NULL;
   int n;
   printf("Enter the information of node of tree\n");
   scanf("%d",&n);
   root=maketree(root,n);
   printf("In order traversal\n");
   root=inorder(root);
}
TREE *getnode()
{
  return((TREE*)malloc(sizeof(TREE *)));
}
TREE *maketree(TREE *root,int key)
{
  
  if(key==-1)
  return(NULL);
  else
  {
    root=getnode();
    root->info=key;
    printf("Enter the left child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->lchild=maketree(root->lchild,key);
    printf("Enter the right child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->rchild=maketree(root->rchild,key);
    return(root);
  }
}
TREE *inorder(TREE *root)
{
  // s.top=-1;
   if(root==NULL)
   return(root);
   while(1) 
   {
      if(root!=NULL)
      {
        push(root); 
        root=root->lchild;
      }
      else
      {
        if(s.top==-1)
        break;
        root=pop();
        printf("%d\t",root->info);
        root=root->rchild;
      }
   }
}
void push(TREE *root)
{
   if(s.top==STACKSIZE-1)
   {
      printf("overflow");
      return;
   }
  a->[++s.top]=root;
}
TREE *pop()
{
  if(s.top==-1)
  {
     printf("underflow");
     return(NULL);
  }
  return(a->[s.top--]);
}

  truct stack STACK;
STACK s;
void push(TREE *);
TREE *pop();
TREE *getnode();
TREE *inorder(TREE *);
TREE *maketree(TREE *,int);
void main()
{
   s.top=-1;
   TREE *root=NULL;
   int n;
   printf("Enter the information of node of tree\n");
   scanf("%d",&n);
   root=maketree(root,n);
   printf("In order traversal\n");
   root=inorder(root);
}
TREE *getnode()
{
  return((TREE*)malloc(sizeof(TREE *)));
}
TREE *maketree(TREE *root,int key)
{

  if(key==-1)
  return(NULL);
  else
  {
    root=getnode();
    root->info=key;
    printf("Enter the left child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->lchild=maketree(root->lchild,key);
    printf("Enter the right child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->rchild=maketree(root->rchild,key);
    return(root);
  }
}
};
typedef struct stack STACK;
STACK s;
void push(TREE *);
TREE *pop();
TREE *getnode();
TREE *inorder(TREE *);
TREE *maketree(TREE *,int);
void main()
{
   s.top=-1;
   TREE *root=NULL;
   int n;
   printf("Enter the information of node of tree\n");
   scanf("%d",&n);
   root=maketree(root,n);
   printf("In order traversal\n");
   root=inorder(root);
}
TREE *getnode()
{
  return((TREE*)malloc(sizeof(TREE *)));
}
TREE *maketree(TREE *root,int key)
{

  if(key==-1)
  return(NULL);
  else
  {
    root=getnode();
    root->info=key;
    printf("Enter the left child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->lchild=maketree(root->lchild,key);
    printf("Enter the right child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->rchild=maketree(root->rchild,key);
    return(root);
  }
}
};
typedef struct stack STACK;
STACK s;
void push(TREE *);
TREE *pop();
TREE *getnode();
TREE *inorder(TREE *);
TREE *maketree(TREE *,int);
void main()
{
   s.top=-1;
   TREE *root=NULL;
   int n;
   printf("Enter the information of node of tree\n");
   scanf("%d",&n);
   root=maketree(root,n);
   printf("In order traversal\n");
   root=inorder(root);
}
TREE *getnode()
{
  return((TREE*)malloc(sizeof(TREE *)));
}
TREE *maketree(TREE *root,int key)
{

  if(key==-1)
  return(NULL);
  else
  {
    root=getnode();
    root->info=key;
    printf("Enter the left child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->lchild=maketree(root->lchild,key);
    printf("Enter the right child(press -1 for NULL)\n");
    scanf("%d",&key);
    root->rchild=maketree(root->rchild,key);
    return(root);
  }
}

