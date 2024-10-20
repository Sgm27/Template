#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
#define maxbit 10
int n,q,h[maxn],par[maxn][maxbit+5],sum[maxn];
vector<pii> adj[maxn];
void dfs(int u)
{
    for (pii v : adj[u])
        if (v.first!=par[u][0])
        {
            h[v.first]=h[u]+1;
            sum[v.first]=sum[u]+v.second;
            par[v.first][0]=u;
            FOR(i,1,maxbit)
                par[v.first][i]=par[par[v.first][i-1]][i-1];
            dfs(v.first);
        }
}
int LCA(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if (delta>>i &1) u=par[u][i];
    if (u==v) return u;
    FOD(i,maxbit,0)
        if (par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    return par[u][0];
}
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        int r=LCA(u,v);
        cout<<sum[u]+sum[v]-2*sum[r]<<"\n";
    }
}
