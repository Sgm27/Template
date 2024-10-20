#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,m,deg[maxn],mark[maxn << 1];
vector<pii> adj[maxn];
vi path;
void dfs(int u)
{
    while (adj[u].size())
    {
        auto [v, idx] = adj[u].back();
        adj[u].pop_back();
        if (mark[idx]) continue;
        mark[idx] = 1;
        dfs(v);
    }
    path.push_back(u);
}
bool check()
{
    FOR(i,1,n)
        if (deg[i] & 1) return false;
    return true;
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
        int u,v; cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        deg[u]++, deg[v]++;
    }
    if (!check()) 
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    dfs(1);
    deb(path.size(),m)
    if (path.size() != m + 1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for (int x : path) 
        cout<<x<<" ";
}
