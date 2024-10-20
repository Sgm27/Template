#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FOD(i,a,b) for (int i=(a);i>=(b);i--)
#define int long long
#define pii pair<int,int>
#define maxn 300005
#define maxbit 19
int n,h[maxn],par[maxn][maxbit+5];
vector<int> adj[maxn];
void dfs(int u)
{
    for (int v : adj[u])
        if (v!=par[u][0])
        {
            h[v]=h[u]+1;
            par[v][0]=u;
            FOR(i,1,maxbit)
                par[v][i]=par[par[v][i-1]][i-1];
            dfs(v);
        }
}
int LCA(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if ((delta>>i)&1) u=par[u][i];
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
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int q; cin>>q;
    while (q--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        int l=LCA(u,v);
        if (h[u]-h[l]+h[v]-h[l]<=w) cout<<v<<"\n";
        else
        if (h[u]-h[l]<=w)
        {
            w-=(h[u]-h[l]);
            int delta=h[v]-h[l]-w;
            FOR(i,0,maxbit)
                if ((delta>>i)&1) v=par[v][i];  
            cout<<v<<"\n";
        }
        else
        {
            FOR(i,0,maxbit)
                if ((w>>i)&1) u=par[u][i];
            cout<<u<<"\n";
        }
    }
}
