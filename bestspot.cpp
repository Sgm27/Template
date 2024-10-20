#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 505
int n,k,m;
vector<int> favorite;
vector<pii> adj[maxn];
int f[maxn];
int dijkstra(int s)
{
    FOR(i,1,n) f[i] = INF;
    f[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({f[s],s});
    while (pq.size())
    {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (du != f[u]) continue;
        for (pii x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (f[v] > f[u] + w)
            {
                f[v] = f[u] + w;
                pq.push({f[v],v});
            }
        }
    }
    int ans = 0;
    for (int x : favorite) 
        ans += f[x];
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k>>m;
    FOR(i,1,k)
    {
        int v; cin>>v;
        favorite.push_back(v);
    }
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int answer = INF, vertex;
    FOR(i,1,n)
    {
        int dis = dijkstra(i);
        if (dis < answer) 
        {
            answer = dis;
            vertex = i;
        }
    }
    cout<<vertex;
}
