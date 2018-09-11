//filling element in a binary search tree and then print in order traversal
#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int info,count;
  struct tree *lchild,*rchild;
};
typedef struct tree TREE;
void inorder(TREE *);
int count_node(TREE *);
int total_sum(TREE *);
TREE *insert(TREE * ,int);
TREE *getnode();
void main()
{
	int m,t,sum;
	TREE *root=NULL;
	printf("enter the element in tree\n");
	while(1)
	{
		scanf("%d",&m);
		if(m==0)
		break;
		root=insert(root,m);
	}
    printf("element in tree\n");
	printf("In order traversal of the tree\n");
	inorder(root);
	printf("\nTotal node present in tree\n");
	t=count_node(root);
	printf("%d",t);
	printf("\nTotal sum of information present in the tree\n");
	sum=total_sum(root);
	printf("%d",sum);
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

void inorder(TREE *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d\t",root->info);
		inorder(root->rchild);
	}
}

int count_node(TREE *root)
{
	if(root==NULL)
	return(0);
    else
	return(1+count_node(root->lchild)+count_node(root->rchild));
}

int total_sum(TREE *root)
{
	if(root==NULL)
	return 0;
    else
	return(root->info+total_sum(root->lchild)+total_sum(root->rchild));
}
