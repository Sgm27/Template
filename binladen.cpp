#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 30005
int n,m,f[maxn];
vector<pii> adj[maxn];
void dijkstra(int s)
{
    FOR(i,1,(n+1)*m) f[i] = INF;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    f[s]=0; 
    pq.push({f[s],s});
    while (!pq.empty())
    {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if (du!=f[u]) continue;
        if (u <= m) return cout<<du, void();
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
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int idx = 0;
    cin>>n>>m;
    FOR(i,1,2*n)
    {
        if (i & 1) 
        {
            FOR(i,1,m)
            {
                int val; cin>>val;
                idx++;
                adj[idx].push_back({idx + m,val});
                adj[idx + m].push_back({idx,val});
            }
        }
        else
        {
            FOR(i,1,m-1)
            {
                int val; cin>>val;
                adj[idx+i].push_back({idx+i+1,val});
                adj[idx+i+1].push_back({idx+i,val});
            }
        }
    }
    dijkstra((n+1) * m);
}
