#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1003
const int INF=1e18;
struct edges{
    int u,v,w;
} e[maxn];
int n,m,s,f[maxn],trace[maxn],ans;
map<pii,int> D,T;
vector<pii> adj[maxn];
void dijkstra()
{
    priority_queue<pii> pq;
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
            if (f[v]<f[u]+w) 
            {
                trace[v]=u;
                f[v]=f[u]+w;
                pq.push({f[v],v});
            }
        }
    }
    ans=f[n];
}
void tracing()
{
    vector<int> path;
    int u=n;
    while (u!=trace[u])
    {
        path.push_back(u);
        u=trace[u];
    }
    path.push_back(1);
    int Max=0;
    reverse(path.begin(),path.end());
    for (int i=0;i<path.size()-1;i++)
    {
        Max=max(Max,D[{path[i],path[i+1]}]*2+T[{path[i],path[i+1]}]);
    }
    // for (int x : path) cout<<x<<" ";
    bool used=false;
    for (int i=0;i<path.size()-1;i++)
    {
        if (!used && D[{path[i],path[i+1]}]*2+T[{path[i],path[i+1]}]==Max) 
        {
            used=true;
            continue;
        }
        else ans+=D[{path[i],path[i+1]}]+T[{path[i],path[i+1]}];
    }
    // cout<<Max<<"\n";
    cout<<ans;
}
signed main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; tc=1;
    while (tc--)
    {
        cin>>n>>m;
        s=1;
        FOR(i,1,n)
        {
            trace[i]=i;
            f[i]=0;
            adj[i].clear();
        }
        FOR(i,1,m) 
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w/2});
            D[{u,v}]=w/2;
            T[{u,v}]=w&1;
        }
        dijkstra();
        tracing();
    }    
}
