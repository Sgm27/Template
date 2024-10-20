#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 10005
int n,m,k,f[maxn][25],ans = INF;
vector<pii> adj[maxn];
struct Node{
    int u,w,used;
    friend bool operator<(const Node a,const Node b)
    {
        return a.w > b.w;
    }
};
void dijkstra(int s)
{
    memset(f,0x3f,sizeof(f));
    priority_queue<Node> pq;
    f[s][0] = 0;
    pq.push({s,0,0});
    while (!pq.empty())
    {
        int u = pq.top().u;
        int du = pq.top().w;
        int used = pq.top().used;
        pq.pop();
        if (du != f[u][used]) continue;
        if (u == n) ans = min(ans,du);
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (f[v][used] > f[u][used] + w)
            {
                f[v][used] = f[u][used] + w;
                pq.push({v,f[v][used],used});
            }
            if (used < k && f[v][used + 1] > f[u][used])
            {
                f[v][used + 1] = f[u][used];
                pq.push({v,f[v][used+1],used+1});
            }
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
    cin>>n>>m>>k;
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(1);
    cout<<ans;
}
