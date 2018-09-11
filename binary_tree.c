#include<stdio.h>
#include<malloc.h>
struct tree
{
  int info;
  struct tree *lchild,*rchild;
};
typedef struct tree TREE;
TREE *maketree(TREE *,int);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE *getnode();
void main()
{
  int n;
  TREE *root=NULL;
  printf("enter the information of root node\n");
  scanf("%d",&n);
  root=maketree(root,n);
  printf("\nIn Order Traversal of tree\n\n");
  inorder(root);
  printf("\n\nPre order Traversal of tree\n\n");
  preorder(root);
  printf("\n\nPost order Traversal of tree\n\n");
  preorder(root);
}

TREE *getnode()
{
  return((TREE *)malloc(sizeof(TREE)));
}

TREE *maketree(TREE *root,int key)
{
  int temp;
//  TREE *p;
  if(key==-1)
  return(NULL);
  else
  {
    root=getnode();
    root->info=key;
    printf("enter the element in left child(press -1 for getting null node)\n");
    scanf("%d",&temp);
    root->lchild=maketree(root->lchild,temp);
    printf("enter the element in right child(press -1 for getting null node)\n");
    scanf("%d",&temp);
    root->rchild=maketree(root->rchild,temp);
    return(root);
  }
}

void inorder(TREE *root)
{
   if(root!=NULL)
   {
      inorder(root->lchild);
      printf("%d-->\t",root->info);
      inorder(root->rchild);
   }
}

void preorder(TREE *root)
{
  if(root!=NULL)
  {
     printf("%d-->\t",root->info);
     preorder(root->lchild);
     preorder(root->rchild);
  }
}

void postorder(TREE *root)
{
   if(root!=NULL)
   {
     preorder(root->lchild);
     preorder(root->rchild);
     printf("%d-->\t",root->info);
   }
}


