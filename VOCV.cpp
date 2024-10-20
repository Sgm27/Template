#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e4+7,INF=4e18;
#define maxn 100015
int n,f[2][maxn],g[2][maxn];
vector<int> adj[maxn];
void dfs(int u,int par)
{
    f[0][u] = 0, f[1][u] = 1;
    g[0][u] = 1, g[1][u] = 1;
    for (int v : adj[u])
        if (v != par)
        {
            dfs(v,u);
            f[0][u] += f[1][v];
            g[0][u] = (g[0][u] * g[1][v]) %MOD;
            f[1][u] += min(f[1][v],f[0][v]);
            if (f[1][v] == f[0][v]) 
                g[1][u] = (g[1][u] * (g[1][v] + g[0][v])) %MOD;
            else
            if (f[1][v] < f[0][v])
                g[1][u] = (g[1][u] * g[1][v]) %MOD;
            else
                g[1][u] = (g[1][u] * g[0][v]) %MOD;
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) adj[i].clear();
        FOR(i,1,n-1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1);
        if (f[1][1] == f[0][1]) 
            cout<<f[1][1]<<" "<<(g[1][1] + g[0][1]) %MOD<<"\n";
        else
        if (f[1][1] < f[0][1])
            cout<<f[1][1]<<" "<<g[1][1]<<"\n";
        else   
            cout<<f[0][1]<<" "<<g[0][1]<<"\n";
    }
}
