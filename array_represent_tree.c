//convert an array into tree
#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int info;
  struct tree *lchild,*rchild;
};
typedef struct tree TREE;
TREE *maketree(int ,int a[],int);
TREE *getnode();
void inorder(TREE *);
void main()
{
  TREE *root=NULL;
  int a[100],n;
  printf("Enter the total no.of node\n");
  scanf("%d",&n);
  printf("enter elements(press -1 for showing null element)\n");
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
  root=maketree(n,a,1);

  printf("In Order traversal of tree\n");
  inorder(root);
}

TREE *maketree(int n,int a[],int i)
{
  TREE *root;
 // int i=0;
  if(a[i]==-1)
  return(NULL);
  if(i<=n)
  {
     root=getnode();
     root->info=a[i];
    
     root->lchild=maketree(n,a,2*i);
    // printf("hi\n");
     root->rchild=maketree(n,a,2*i+1);
    // printf("hello\n");
     return(root);
  }
  
//  return(root);
}

TREE *getnode()
{
  return((TREE *)malloc(sizeof(TREE)));
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

    
    

