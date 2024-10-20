#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 500005 
int n,m,s1,s2,h1,h2;
int d[4][maxn];
vector<pii> g[maxn];

void dijkstra(int s,int idx)
{
    FOR(i,1,n) d[idx][i] = INF;
    d[idx][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[idx][s], s});
    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != d[idx][u]) continue;
        for (auto [v,w] : g[u])
            if (d[idx][v] > d[idx][u] + w)
            {
                d[idx][v] = d[idx][u] + w;
                pq.push({d[idx][v], v});
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
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        cin>>h1>>s1>>h2>>s2;
        FOR(i,1,n) g[i].clear();
        struct edge{
            int u,v,w;
        };
        vector<edge> edges;
        FOR(i,1,m)
        {
            int u,v,w; 
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            edges.push_back({u,v,w});
        }

        dijkstra(h1, 0);
        dijkstra(s1, 1);
        dijkstra(h2, 2);
        dijkstra(s2, 3);

        int ans = 0;

        FOR(i,1,n)
        {
            if (d[0][i] + d[1][i] != d[0][s1] || d[2][i] + d[3][i] != d[2][s2]) continue;
            if (d[0][i] == d[2][i]) ans++;
            if (i == s1 && d[2][i] < d[0][i]) ans++;
            if (i == s2 && d[0][i] < d[2][i]) ans++;  
        }

        for (auto [u,v,w] : edges)
        {
            if (d[0][u] + w + d[1][v] == d[0][s1])
            {
                if (d[2][u] + w + d[3][v] == d[2][s2] && d[0][u] == d[2][u]) ans = INF;
                if (d[2][v] + w + d[3][u] == d[2][s2])
                {
                    assert(d[0][u] + w == d[0][v]);
                    if (d[0][u] < d[2][u] && d[0][v] > d[2][v]) ans++;
                }
            }

            swap(u,v);

            if (d[0][u] + w + d[1][v] == d[0][s1])
            {
                if (d[2][u] + w + d[3][v] == d[2][s2] && d[0][u] == d[2][u]) ans = INF;
                if (d[2][v] + w + d[3][u] == d[2][s2])
                {
                    assert(d[0][u] + w == d[0][v]);
                    if (d[0][u] < d[2][u] && d[0][v] > d[2][v]) ans++;
                }
            }
        }

        if (ans >= INF) cout<<"infinity\n";
        else cout<<ans<<"\n";
    }
}
