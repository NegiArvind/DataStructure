//convert a tree into threaded tree 
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
    if(key==-1)
    root->rhild=inorderpredeccesor(root->rchild);
    else
    root->lchild=maketree(root->lchild,key);
    printf("Enter the right child(press -1 for NULL)\n");
    scanf("%d",&key);
    if(key==-1)
    root->rhild=inordersuccesor(root->rchild);
    else
    root->rchild=maketree(root->rchild,key);
    return(root);
  }
}
TREE *inordersuccesor(TREE *root)
{
                                                                       
