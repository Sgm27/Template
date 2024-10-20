#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxbit 17
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,h[maxn],par[maxn][maxbit+1];
int f[maxn],ans;
struct adjacent{
    int v,c1,c2;
};
vector<adjacent> adj[maxn];
void dfs(int u)
{
    for (auto it : adj[u])
    {
        int v = it.v;
        if (v == par[u][0]) continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        FOR(i,1,maxbit)
            par[v][i] = par[par[v][i-1]][i-1];
        dfs(v);
    }
}
int LCA(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    FOD(i,maxbit,0)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
void reDfs(int u)
{
    for (auto it : adj[u])
    {
        int v = it.v;
        if (v == par[u][0]) continue;
        reDfs(v);
        f[u] += f[v];
        ans += min(it.c1 * f[v],it.c2);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v,c1,c2;
        cin>>u>>v>>c1>>c2;
        adj[u].push_back({v,c1,c2});
        adj[v].push_back({u,c1,c2});
    }
    dfs(1);
    FOR(i,1,n-1)
    {
        int p = LCA(i,i+1);
        f[p] -= 2;
        f[i]++, f[i+1]++;
    }
    reDfs(1);
    cout<<ans;
}
