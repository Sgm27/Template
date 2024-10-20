#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 300005
#define maxbit 19
int n,m,h[maxn],root;
vector<pii> adj[maxn];
struct LCA{
    int par,Min,Max;
    LCA()
    {
        par = 0;
        Min = INF;
        Max = -INF;
    }
} p[maxn][maxbit+2];
void dfs(int u)
{
    for (auto it : adj[u])
    {
        int v = it.first;
        int w = it.second;
        if (v != p[u][0].par)
        {
            h[v] = h[u] + 1;
            p[v][0].par = u;
            p[v][0].Max = w;
            p[v][0].Min = w;
            FOR(i,1,maxbit)
            {
                p[v][i].par = p[p[v][i-1].par][i-1].par;
                p[v][i].Min = min(p[p[v][i-1].par][i-1].Min,p[v][i-1].Min);
                p[v][i].Max = max(p[p[u][i-1].par][i-1].Max,p[v][i-1].Max);
            }
            dfs(v);
        }
    }
}
pii LCA(int u,int v)
{
    pii ans = {INF,-INF};
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit)
        if ((delta >> i) & 1) 
        {
            ans.first = min(ans.first,p[u][i].Min);
            ans.second = max(ans.second,p[u][i].Max);
            u = p[u][i].par;
        }
    if (u == v) return ans;
    FOD(i,maxbit,0)
        if (p[u][i].par != p[v][i].par)
        {
            ans.first = min({ans.first,p[u][i].Min,p[v][i].Min});
            ans.second = max({ans.second,p[u][i].Max,p[v][i].Max});
            u = p[u][i].par;
            v = p[v][i].par;
        }
    ans.first = min({ans.first,p[u][0].Min,p[v][0].Min});
    ans.second = max({ans.second,p[u][0].Max,p[v][0].Max});
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
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    int q; cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v).first<<"\n";
    }
}
