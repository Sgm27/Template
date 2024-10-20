#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 10005
int n,f[maxn],k,m,s,t,dis[2][maxn];
vector<pii> adj1[maxn],adj2[maxn];
void dijkstra(int s,int idx,vector<pii> adj[])
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    FOR(i,1,n) f[i] = INF;
    f[s]=0; 
    pq.push({f[s],s});
    while (!pq.empty())
    {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (du!=f[u]) continue;
        for (pii x : adj[u])
        {
            int v=x.first;
            int w=x.second;
            if (f[v]>f[u]+w) 
            {
                f[v]=f[u]+w;
                pq.push({f[v],v});
            }
        }
    }
    FOR(i,1,n) dis[idx][i] = f[i];
}
struct edge{
    int u,v,w;
};
vector<edge> edges;
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
        cin>>n>>m>>k>>s>>t;
        FOR(i,1,n) adj1[i].clear(), adj2[i].clear();
        edges.clear();
        FOR(i,1,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj1[u].push_back({v,w});
            adj2[v].push_back({u,w});
        }
        FOR(i,1,k) 
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        dijkstra(s,0,adj1);
        dijkstra(t,1,adj2);
        int min_cost = dis[0][t];
        for (auto it : edges)
        {
            int u = it.u;
            int v = it.v;
            int w = it.w;
            if (dis[0][u] + w + dis[1][v] < min_cost) 
                min_cost = dis[0][u] + w + dis[1][v];
            swap(u,v);
            if (dis[0][u] + w + dis[1][v] < min_cost) 
                min_cost = dis[0][u] + w + dis[1][v];
        }
        cout<<(min_cost == INF ? -1 : min_cost)<<"\n";
    }
}
