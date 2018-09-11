#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int info,count;
  struct tree *lchild,*rchild;
};
typedef struct tree TREE;
TREE *insert(TREE *,int);
TREE *delete(TREE *,int);
TREE *inordersuccessor(TREE *);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE *getnode();
void main()
{
  int m,n;
  TREE *root=NULL;
  printf("enter the element which you want to insert(press 0 for terminating)\n");
  while(1)
  {
    scanf("%d",&m);
    if(m==0)
    break;
    root=insert(root,m);
  }
  printf("enter the information of that element which you want to delete\n");
  scanf("%d",&n);
  root=delete(root,n);
  printf("preorder traversal is:\t");
  preorder(root);
  printf("\n");
  printf("inorder traversal is:\t");
  inorder(root);
  printf("\n");
  printf("postorder traversal is:\t");
  postorder(root);
  printf("\n");
}
TREE *getnode()
{
  return((TREE *)malloc(sizeof(TREE)));
}
TREE *insert(TREE *root,int key)
{
  TREE *q;
  if(root==NULL)
  {
    root=getnode();
    root->info=key;
    root->lchild=NULL;
    root->rchild=NULL;
    root->count=1;
    return(root);
  }
  else if(key<root->info)
       {
        root->lchild=insert(root->lchild,key);
       }
       else if(key>root->info)
       {
        root->rchild=insert(root->rchild,key);
       }
       else
       root->count++;
   return(root);
}
TREE *delete(TREE *root,int key)
{
  TREE *temp;
  if(root==NULL)
  return(root);
  else if(key<root->info)
       {
        root->lchild=delete(root->lchild,key);
       }
       else if(key>root->info)
       {
        root->rchild=delete(root->rchild,key);
       }
       else
       {
          if(root->lchild==NULL)
          {
            temp=root->rchild;
            free(root);
            return(temp);
          }
          else if(root->rchild==NULL)
              {
                temp=root->lchild;
                free(root);
                return(temp);
              }
              else
              {
                temp=inordersuccessor(root);
                root->info=temp->info;
                temp->rchild=delete(temp->rchild,temp->info);
              }
         }
        return(root);
}
TREE *inordersuccessor(TREE *root)
{
  TREE *p=root;
  int j,i=0;
  TREE *a[20];
  if(root!=NULL)
  {
    root->lchild=inordersuccessor(root->lchild);
    a[i++]=inordersuccessor(root);
    root->rchild=inordersuccessor(root->rchild);
    for(j=0;j<i;j++)
    {
      if(p->info==a[j]->info)
      {
        return(a[j++]);
      }
    }
  }
}

void inorder(TREE *root)
{
  if(root!=NULL)
  {
    inorder(root->lchild);
    printf("%d\t",root->info);
    inorder(root->rchild);
  }
}

void preorder(TREE *root)
{
  if(root!=NULL)
  {
     printf("%d\t",root->info);
    inorder(root->lchild);
    inorder(root->rchild);
  }
}

void postorder(TREE *root)
{
  if(root!=NULL)
  {
    inorder(root->lchild);
    inorder(root->rchild);
    printf("%d\t",root->info);
  }
}
            
                
           
            
          
