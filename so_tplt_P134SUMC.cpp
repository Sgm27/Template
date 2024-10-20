#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 20004
vector<int> adj[maxn];
int n,m,par[maxn],child[maxn],id[maxn],low[maxn],dfs_timer,cc;
void Tarjan(int u)
{
    child[u]=(par[u]!=-1);
    low[u]=id[u]=++dfs_timer;
    for (int v : adj[u])
        if (v != par[u])
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                Tarjan(v);
                low[u]=min(low[u],low[v]);
                if (low[v]>=id[u]) child[u]++;
            }
        }
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
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i,1,n)  
        if (!par[i]) 
        {
            par[i]=-1, Tarjan(i);
            cc++;
        }
    FOR(i,1,n) cout<<child[i]+cc-1<<"\n";
}
