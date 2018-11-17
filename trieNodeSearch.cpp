#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)

/**------- ShortCuts----------*/
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<int, int>        pii;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<pii>           vii;
typedef vector<iii>           viii;
 
/**--------Constant------------*/
#define mx5                100001
#define mx6                1000001
#define FF                 first
#define SE                 second
#define all(x)             x.begin(), x.end()
#define INF                0x3f3f3f3f
#define eps                1e-8
#define PI                 acos(-1.0)
#define mem(x, y)          memset(x, y, sizeof(x))


struct trieNode
{
    struct trieNode *children[26];
    bool endofword;
    int count;
};
typedef struct trieNode TrieNode;

TrieNode *newNode()
{
    TrieNode *node=new trieNode;
    for(int i=0;i<26;i++)
    node->children[i]=NULL;
    node->endofword=false;
    node->count=0;
    return node;
}
void insert(TrieNode *root,string s)
{
    TrieNode *node=new trieNode;
    node=root;
    for(int i=0;i<s.length();i++)
    {
        if(node->children[s[i]-97]==NULL)
        node->children[s[i]-97] = newNode();
        node=node->children[s[i]-97];
        node->count+=1;
        cout<<""<<"\n";
    }
    // node->isfree=false;
    // node->count+=1;
    node->endofword=true;
}

int search(TrieNode *root,string s)
{
    TrieNode *node=root;
    for(int i=0;i<s.length();i++)
    {
        if(node->children[s[i]-97]==NULL)
        return 0;
        node=node->children[s[i]-97];
    }
    return node->count;
}

int main()
{
    int n;
    cin>>n;
    string s,s1;
    TrieNode *root=newNode();
    while(n--)
    {
        cin>>s;
        if(s.compare("add")==0)
        {
            cin>>s1;
            insert(root,s1);
        }
        else
        {
            cin>>s1;
            cout<<search(root,s1)<<"\n";
        }
    }
}