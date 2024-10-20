#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
struct Node{
    int l,r,val;
    Node *left, *right;
    Node(int _l,int _r)
    {
        l = _l, r = _r;
        val = 0;
        left = right = NULL;
    }
};
Node *root[maxn];
struct Segment_Tree{
    Node *makeTree(int cur,int l,int r)
    {
        Node *p = new Node(l,r);
        if (l < r)
        {
            int m = l+r >> 1;
            p->left = makeTree(cur,l,m);
            p->right = makeTree(cur,m+1,r);
        }
        return p;
    }
    void update(Node *p,int pos,int val)
    {
        if (p->l == p->r) 
        {
            p->val = val;
            return;
        }
        int m = (p->l + p->r) >> 1;
        if (pos <= m) 
            update(p->left,pos,val);
        else 
            update(p->right,pos,val);
        p->val = max(p->left->val, p->right->val);
    }
    int get(Node *p,int u,int v)
    {
        if (p->r < u || p->l > v) return 0;
        if (p->l >= u && p->r <= v) return p->val;
        return max(get(p->left,u,v), get(p->right,u,v));
    }
} ST;
// ================HLD==================

vector<int> chain[maxn], adj[maxn];
int sz[maxn], Height[maxn], Par[maxn], chainID[maxn], pos[maxn];
void dfs_setup(int u,int par,int height)
{
    Par[u] = par;
    Height[u] = height;
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == par) continue;
        dfs_setup(v,u,height+1);
        sz[u] += sz[v];
    }
}

void HLD(int u)
{
    chain[u].push_back(u);
    for (int i = 0;i < chain[u].size(); i++)
    {
        int v = chain[u][i];
        chainID[v] = u;
        pos[v] = i;
        for (int vv : adj[v])
            if (vv != Par[v])
                if (sz[vv] * 2 >= sz[v]) chain[u].push_back(vv);
                else HLD(vv);
    }
    root[u] = ST.makeTree(u,0,chain[u].size() - 1);
}

int HLD_query(int u,int v)
{
    int ans = 0;
    while (chainID[u] != chainID[v])
    {
        if (Height[chainID[u]] > Height[chainID[v]]) swap(u,v);
        ans = max(ans, ST.get(root[chainID[v]], 0, pos[v]));
        v = Par[chainID[v]];
    }
    if (pos[u] > pos[v]) swap(u,v);
    ans = max(ans, ST.get(root[chainID[u]], pos[u], pos[v]));
    return ans;
}
int n,q,a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_setup(1,1,0);
    HLD(1);
    for (int i = 1;i <= n;i++)
        ST.update(root[chainID[i]], pos[i], a[i]);
    while (q--)
    {
        int type;
        cin>>type;
        if (type == 1)
        {
            int idx,val;
            cin>>idx>>val;
            ST.update(root[chainID[idx]], pos[idx], val);
        }
        else
        {
            int u,v; cin>>u>>v;
            cout<<HLD_query(u,v)<<" ";
        }
    } 

}
