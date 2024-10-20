#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxbit 20
#define maxn 
int q,SZ;
struct Node{
    Node* child[2];
    int count,exist;
    int val;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = val = 0;
    }
};
Node *root = new Node();
void Add(int val)
{
    Node *p=root;
    FOD(i,maxbit,0) 
    {
        int id = (val >> i) & 1;
        if (p->child[id] == NULL) p->child[id] = new Node();
        p = p -> child[id];
        p -> count++;
    }
    p -> exist++;
    p -> val = val;
}
void Del(int val)
{
    Node *p=root;
    FOD(i,maxbit,0)
    {
        int id = (val >> i) & 1;
        p -> child[id] -> count--;
        if (p -> child[id] -> count == 0) 
        {
            p -> child[id] = NULL;
            return;
        }
        p = p -> child[id];
    }
    p -> exist--;
}
int Get(int cnt)
{
    Node *p=root;
    FOD(i,maxbit,0)
    {
        if (p->child[0] != NULL && p->child[0]->count >= cnt)
            p = p->child[0];
        else
        {
            if (p->child[0] != NULL) cnt -= p->child[0]->count;
            p = p->child[1];
        }
    }
    return p->val;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>q;
    while (q--)
    {
        string type; cin>>type;
        if (type == "add")
        {
            int val; cin>>val;
            SZ++;
            Add(val);
        }
        else
        if (type == "del")
        {
            int val; cin>>val;
            SZ--;
            Del(val);
        }
        else
            cout<<Get((SZ+1)/2)<<"\n";
    }
}
