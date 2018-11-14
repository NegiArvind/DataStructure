#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int j=0;
int b[100001];
struct node
{
    int value;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node NODE;
NODE *getnode()
{
    return (NODE *)malloc(sizeof(NODE));
}
NODE * newNode(int item)
{
    NODE * temp=getnode();
    temp->lchild=NULL;
    temp->rchild=NULL;
    temp->value=item;
    return temp;
}
int minSwaps(int arr[], int n) 
{ 
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if(cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
}
NODE * insert(int a[],NODE *root,int i,int n)
{
    if(i<n)
    {
        NODE *temp=newNode(a[i]);
        root=temp;
        
        root->lchild=insert(a,root->lchild,2*i+1,n);
        root->rchild=insert(a,root->rchild,2*i+2,n);
    }
    return root;
}
void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        b[j++]=root->value;
        inorder(root->rchild);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    int a[n+1];
    NODE *root=NULL;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        // root=insert(root,x);
    }
    root=insert(a,root,0,n);
    inorder(root);
    cout<<minSwaps(b,n);
}