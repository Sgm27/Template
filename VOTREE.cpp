#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxbit 17
#define maxn 70005
int n,q,h[maxn],p[maxn][maxbit + 2];
vector<int> adj[maxn];
void dfs(int u)
{
    for (int v : adj[u])
        if (v != p[u][0]) 
        {
            h[v] = h[u] + 1;
            p[v][0] = u;
            FOR(i,1,maxbit)
                p[v][i] = p[p[v][i-1]][i-1];
            dfs(v);
        }
}
int getLCA(int u,int v)
{
    if (u == -1) return v;
    if (v == -1) return u; 
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit) 
        if ((delta >> i) & 1) u = p[u][i];
    if (u == v) return u;
    FOD(i,maxbit,0)
        if (p[u][i] != p[v][i]) 
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
struct Segment_Tree{
    vector<int> t;
    Segment_Tree (int _sz)
    {
        t.assign(_sz << 2,-1);
    }
    void build(int id,int l,int r)
    {
        if (l == r) 
            return t[id] = l, void();
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id] = getLCA(t[id << 1], t[id << 1 | 1]);
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return -1;
        if (l>=u && r<=v) return t[id];
        int m = l+r >> 1;
        return getLCA(get(id << 1,l,m,u,v),get(id << 1 | 1,m+1,r,u,v)); 
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    Segment_Tree ST(n);
    ST.build(1,1,n);
    while (q--)
    {
        int u,v; 
        cin>>u>>v;
        cout<<ST.get(1,1,n,u,v)<<"\n";
    }
}
