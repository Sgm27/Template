#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxbit 31
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,a[maxn],q;
struct Node{
    Node *child[2];
    int count, exist;
    Node()
    {
        memset(child, 0, sizeof(child));
        count = exist = 0;
    }
};
Node *root = new Node();
void Add(int val)
{
    Node *p = root;
    for (int i = maxbit;i>=0;i--)
    {
        int id = (val >> i) & 1;
        if (p->child[id] == NULL) p->child[id] = new Node();
        p = p->child[id];
        p->count++;
    }
    p->exist++;
}
void Del(int val)
{
    Node *p = root;
    for (int i = maxbit; i>=0;i--)
    {
        int id = (val >> i) & 1;
        p->child[id]->count--;
        if (p->child[id]->count == 0)
        {
            p->child[id]->exist--;
            p->child[id] = NULL;
            return;
        }
        p = p->child[id];
    }
    p->exist--;
}
int lessK(int val)
{
    Node *p = root;
    int ans = 0;
    for (int i = maxbit;i>=0;i--)
    {
        int id = (val >> i) & 1;
        if (id == 1 && p->child[0] != NULL) 
            ans += p->child[0]->count; 
        if (p->child[id]) p = p->child[id];
        else 
        return ans;
    }
    return ans + p->count;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n)
    {
        cin>>a[i];
        Add(a[i]);
    }
    while (q--)
    {
        string type; cin>>type;
        if (type == "?") 
        {
            int l,r; cin>>l>>r;
            cout<<lessK(r) - lessK(l-1)<<"\n";
        }
        else
        {
            int pos,val;
            cin>>pos>>val;
            Del(a[pos]);
            a[pos] = val;
            Add(a[pos]);
        }
    }
}
