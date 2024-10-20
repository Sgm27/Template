#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 105
int n,k,m;
int f[maxn][10005];
struct IJK{
    int u,w,money;
    friend bool operator<(const IJK a,const IJK b)
    {
        return a.w>b.w;
    }
};
struct edge{
    int v,len,money;
};
vector<edge> adj[maxn];
void dijkstra(int s)
{
    FOR(i,1,n) 
        FOR(j,0,k) f[i][j] = INF;
    priority_queue<IJK> pq;
    pq.push({s,0,k});
    int ans = INF;
    f[s][k] = 0;
    while (!pq.empty())
    {
        int u = pq.top().u;
        int du = pq.top().w;
        int money = pq.top().money;
        pq.pop();
        if (du != f[u][money]) continue;
        if (u == n) return cout<<du<<"\n", void();
        for (auto it : adj[u])
        {
            int v = it.v;
            int w = it.len;
            int m2 = it.money;
            if (money - m2 >= 0 && f[v][money - m2] > f[u][money] + w)
            {
                f[v][money - m2] = f[u][money] + w;
                pq.push({v,f[v][money-m2],money-m2});
            }
        }
    }
    cout<<"-1\n";
}
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
        cin>>k>>n>>m;
        FOR(i,1,n) adj[i].clear();
        FOR(i,1,m)
        {
            int u,v,len,money;
            cin>>u>>v>>len>>money;
            edge x = {v,len,money};
            adj[u].push_back(x);
        }
        dijkstra(1);
    }
}
