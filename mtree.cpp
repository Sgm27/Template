#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,f[maxn],ans = 0;
vector<pii> adj[maxn];
void dfs(int u,int par)
{
    f[u] = 1;
    int have = 1;
    for (auto it : adj[u])
    {
        int v = it.first;
        int w = it.second;
        if (v == par) continue;
        dfs(v,u);
        ans = (ans + w * (have * f[v] %MOD))%MOD;
        have = (have + w * f[v])%MOD;
    }
    f[u] = have;
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,-1);
    cout<<ans;
}
