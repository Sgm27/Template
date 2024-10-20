#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pli pair<long double,int>
using ld = long double;
const ld eps = 1e-12;
#define maxn 1005
int n,m,k;
vector<pair<int,int>> adj[maxn];
ld f[15][maxn];
struct Node{
    int u,used;
    ld w;
    friend bool operator<(const Node a,const Node b)
    {
        return a.w > b.w;
    }
};
Node make_node(int _u,int _used,ld _w)
{
    Node ans;
    ans.u = _u , ans.used = _used , ans.w = _w;
    return ans;
}
void dijkstra(int s)
{
    FOR(K,0,k) FOR(i,1,n) f[K][i] = 1e12;
    priority_queue<Node> pq;
    f[0][s]=0.0; 
    pq.push(make_node(s,0,0.0));
    while (!pq.empty())
    {
        ld du=pq.top().w;
        int u=pq.top().u;
        int used=pq.top().used;
        pq.pop();
        if (abs(du - f[used][u]) > eps) continue;
        if (used == k && u == n) 
        {
            cout<<fixed<<setprecision(2)<<du;
            return;
        }
        for (pair<int,int> x : adj[u])
        {
            int v=x.first;
            int w=x.second;
            FOR(i,used,k)
            {
                if (f[i][v] > f[used][u] + 1.0*w / (1.0*(1<<(i-used))))
                {
                    f[i][v] = f[used][u] + 1.0*w / (1.0*(1<<(i-used)));
                    pq.push({make_node(v,i,f[i][v])});
                }
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
}
