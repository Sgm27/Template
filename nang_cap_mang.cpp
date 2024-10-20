#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxbit 17
#define maxn 100005
int n,m,h[maxn];
vector<pii> adj[maxn];
struct LCA{
    int par,minn;
    LCA()
    {
        par = 0;
        minn = INF;
    }
} p[maxn][maxbit + 2];
struct edge{
    int u,v,w;
    friend bool operator<(const edge a,const edge b)
    {
        return a.w > b.w;
    }
};
vector<edge> edges;
struct DSU{
    vector<int> r;
    int n;
    DSU(int sz)
    {
        n=sz;
        r.resize(sz+1);
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    bool join(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return 0;
        return r[u]=v, 1;
    }
};
void make_MST() // maximum spaning tree
{
    sort(edges.begin(), edges.end());
    int nEdge = 0;
    DSU dsu(n);
    for (edge e : edges)
    {
        if (dsu.join(e.u,e.v)) 
        {
            nEdge++;
            adj[e.u].push_back({e.v,e.w});
            adj[e.v].push_back({e.u,e.w});
        }
        if (nEdge == n-1) break;
    }
}
void dfs(int u)
{
    for (auto it : adj[u])
    {
        int v = it.first;
        int w = it.second;
        if (v == p[u][0].par) continue;
        h[v] = h[u] + 1;
        p[v][0].par = u;
        p[v][0].minn = w;
        FOR(i,1,maxbit)
        {
            p[v][i].par = p[p[v][i-1].par][i-1].par;
            p[v][i].minn = min(p[v][i-1].minn, p[p[v][i-1].par][i-1].minn);
        }
        dfs(v);
    }
}
int getMinEdge(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v],ans = INF;
    FOD(i,maxbit,0) 
        if ((delta >> i) & 1) 
        {
            ans = min(ans, p[u][i].minn);
            u = p[u][i].par;
        }
    if (u == v) return ans;
    FOD(i,maxbit,0)
        if (p[v][i].par != p[u][i].par) 
        {
            ans = min(ans, p[u][i].minn);
            ans = min(ans, p[v][i].minn);
            u = p[u][i].par;
            v = p[v][i].par;
        }
    ans = min({ans, p[u][0].minn, p[v][0].minn});
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    make_MST();
    dfs(1); // build LCA of MST
    int updWeight = 0;
    for (auto e : edges)
        updWeight += getMinEdge(e.u, e.v) - e.w;
    cout<<updWeight;
}
