#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,h[maxn],par[maxn][20];
vector<int> adj[maxn];
void dfs(int u)
{
    for (int v : adj[u])
        if (v!=par[u][0])
        {
            h[v]=h[u]+1;
            par[v][0]=u;
            FOR(i,1,13)
                par[v][i]=par[par[v][i-1]][i-1];
            dfs(v);
        }
}
int LCA(int u,int v)
{
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,13) 
        if ((delta>>i)&1) u=par[u][i];
    if (u==v) return u;
    FOD(i,13,0)
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
    int tc,count=0; cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<++count<<":\n";
        FOR(i,1,n) adj[i].clear();
        cin>>n;
        FOR(i,1,n)
        {
            int s; cin>>s;
            FOR(j,1,s) 
            {
                int x; cin>>x;
                adj[i].push_back(x);
            }
        }	
        dfs(1);
        int q; cin>>q;
        while (q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<LCA(u,v)<<"\n";
        }
    }
}
