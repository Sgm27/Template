#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define maxbit 30
#define pii pair<int,int>
#define int long long
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n;
struct Trie{
    struct Node{
        Node *child[2];
        int count,exist;
        Node()
        {
            memset(child,0,sizeof(child));
            count = exist = 0;
        }
    };

    Node *root = new Node();

    void add(int val)
    {
        Node *p = root;
        FOD(i,maxbit,0)
        {
            int id = (val >> i) & 1;
            if (p->child[id] == NULL) p->child[id] = new Node();
            p = p->child[id];
            p->count++;
        }
        p->exist++;
    }
    
    int minXor(int val)
    {
        Node *p = root;
        int ans = 0;
        FOD(i,maxbit,0)
        {
            int id = (val >> i) & 1;
            if ((p->child[id] == NULL) || (p->child[id]->count == 0))
            {
                ans += (1<<i);
                p = p->child[id ^ 1];
            }
            else
                p = p->child[id];
        }
        return ans;
    }

    void clear(Node *p)
    {
        if (p->child[0] != NULL && p->child[0]->count != 0)
        {
            p->child[0]->count = 0;
            clear(p->child[0]);
        }
        if (p->child[1] != NULL && p->child[1]->count != 0)
        {
            p->child[1]->count = 0;
            clear(p->child[1]);
        }
    }
} tree;
int Query(vector<int> a,int idx)
{
    if (idx < 0) return 0;
    vector<int> v0,v1;
    for (int x : a)
        if ((x >> idx) & 1) v1.push_back(x);
        else v0.push_back(x);
    if (v0.size() == 0)
        return Query(v1,idx-1);
    if (v1.size() == 0)
        return Query(v0,idx-1);
    tree.clear(tree.root);
    for (int x : v0) tree.add(x);
    int ans = INF;
    for (int x : v1)
        ans = min(ans, tree.minXor(x));
    return ans + Query(v0,idx-1) + Query(v1,idx-1);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> a;
    cin>>n;
    FOR(i,1,n)
    {
        int v; cin>>v;
        a.push_back(v);
    }
    cout<<Query(a,maxbit);
}
