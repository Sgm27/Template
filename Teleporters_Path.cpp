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
int n,m,in_deg[maxn],out_deg[maxn],mark[maxn << 1];
vector<pii> adj[maxn];
vi path;
bool check()
{
    if (in_deg[1] != out_deg[1] - 1 || in_deg[n] != out_deg[n] + 1) 
        return false;
    FOR(i,2,n-1)
        if (in_deg[i] != out_deg[i]) return false;
    return true;
}
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
        in_deg[v]++, out_deg[u]++;
    }
    if (!check()) 
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    m++;
    adj[n].push_back({1,m});
    dfs(1);
    if (path.size() != m+1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(ALL(path));
    path.pop_back();
    int pos = 0;
    FOR(i,1,path.size()-1)
        if (path[i-1] == n && path[i] == 1) 
        {
            pos = i;
            break;
        } 
    FOR(i,pos,path.size()-1) cout<<path[i]<<" ";
    FOR(i,0,pos-1) cout<<path[i]<<" ";
}
