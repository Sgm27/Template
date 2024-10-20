#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 5005
vector<pii> adj[maxn];
int n,m,f[maxn],g[maxn];
void dijkstra(int s)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    f[s] = 0;
    g[s] = 1;
    pq.push({f[s],s});
    while (!pq.empty())
    {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (du != f[u]) continue;
        for (pii x : adj[u])
        {
            int v=x.first;
            int w=x.second;
            if (f[v]>f[u]+w) 
            {
                f[v] = f[u]+w;
                g[v] = g[u];
                pq.push({f[v],v});
            }
            else
            if (f[v] == f[u] + w) g[v] += g[u];
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
    FOR(i,1,n) f[i] = INF;
    FOR(i,1,m) 
    {
        int type,u,v,w;
        cin>>type>>u>>v>>w;
        adj[u].push_back({v,w});
        if (type == 2)
            adj[v].push_back({u,w});
    }
    dijkstra(1);
    cout<<f[n]<<" "<<g[n];
}
