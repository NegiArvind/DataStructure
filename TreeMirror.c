#include<stdio.h>
#include<malloc.h>
struct tree
{
   int info,count;
   struct tree *lchild,*rchild;
};
typedef struct tree TREE;
TREE *getnode();
TREE *insert(TREE *,int);
TREE *mirrorImage(TREE *);
void inorder(TREE *);
void swap(TREE **,TREE **);
void main()
{
   int n;
   TREE *root=NULL,*root1=NULL;
   printf("enter the elements which you want to insert(press -1 for temination)\n");
   while(1)
   {
      scanf("%d",&n);
      if(n==-1)
      break;
      root=insert(root,n);
   }
   printf("\nIn order traversal of binary tree\n");
   inorder(root);
   printf("\nInorder traversal of its mirror image \n");
   root=mirrorImage(root);
   inorder(root);
}
TREE *getnode()
{
   return((TREE *)malloc(sizeof(TREE)));
}
TREE *insert(TREE *root,int key)
{
  if(root==NULL)
  {
      root=getnode();
      root->info=key;
      root->lchild=NULL;
      root->rchild=NULL;
      root->count=1;
  }
  if(key<root->info)
  root->lchild=insert(root->lchild,key);
  else if(key>root->info)
        root->rchild=insert(root->rchild,key);
        else
        root->count++;
        return(root);
}
TREE *mirrorImage(TREE *root)
{
   if(root==NULL)
   return NULL;
   if(root->lchild!=NULL||root->rchild!=NULL)
   {   
      swap(&root->lchild,&root->rchild);
      root->lchild=mirrorImage(root->lchild);
      root->rchild=mirrorImage(root->rchild);
   }
   return(root);
}
void swap(TREE **root1,TREE **root2)
{
   TREE *temp;
   temp=*root1;
   *root1=*root2;
   *root2=temp;
}
void inorder(TREE *root)
{
  if(root!=NULL)
  {
    inorder(root->lchild);
    printf("%d->",root->info);
    inorder(root->rchild);
  }
  printf("\n");
}

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  



      


