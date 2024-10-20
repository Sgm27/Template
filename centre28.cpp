#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 30005
int n,f[maxn],g[maxn],m;
int dis[2][maxn],cnt[2][maxn];
bool Important[maxn];
vector<pii> adj[maxn];
void dijkstra(int s,int idx)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    FOR(i,1,n) f[i] = INF, g[i] = 0;
    f[s]=0; 
    g[s]=1;
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
                g[v]=g[u];
                f[v]=f[u]+w;
                pq.push({f[v],v});
            }
            else
            if (f[v] == f[u] + w) g[v]+=g[u];
        }
    }
    FOR(i,1,n)
    {
        dis[idx][i] = f[i];
        cnt[idx][i] = g[i];
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(1,0);
    dijkstra(n,1);
    int min_cost = dis[0][n], count = cnt[0][n], ans = 0;
    FOR(i,1,n)
    {
        if (dis[0][i] + dis[1][i] == min_cost && cnt[0][i] * cnt[1][i] == count) 
        {
            Important[i] = 1;
            ans++;
        }
    }
    cout<<n - ans<<"\n";
    FOR(i,1,n)
        if (!Important[i]) cout<<i<<"\n";
}
