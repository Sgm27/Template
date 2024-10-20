#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005
int n,m,s,t;
struct Edge {
    int u, v, cap, flow;
};
struct MaxFlow {
    int n, S, T;
    vector <int> d, ptr, q; // if (d[s] == -1) -> s can't reachable 
    vector <Edge> e;
    vector <vector <int>> ke;
    MaxFlow(int n) : n(n + 5), d(n + 5), ptr(n + 5), ke(n + 5), q(n + 5) {}
    void reset() {
        fill(d.begin(), d.end(), 0); fill(ptr.begin(), ptr.end(), 0); fill(ke.begin(), ke.end(), vector <int>());
    }
    void addEdge(int u, int v, int cap) {
        Edge e1 = {u, v, cap, 0};
        Edge e2 = {v, u, 0, 0}; // if two-way edge not need to add e2
        e.push_back(e1); ke[u].push_back((int) e.size() - 1);
        e.push_back(e2); ke[v].push_back((int) e.size() - 1);
    }
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = S;
        fill(d.begin(), d.end(), -1);
        d[S] = 0;
        while (qh < qt && d[T] == -1) {
            int v = q[qh++];
            for (int i = 0; i < (int) ke[v].size(); i++) {
                int id = ke[v][i], to = e[id].v;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[T] != -1;
    }
    int dfs (int u, int flow) {
        if(!flow) return flow;
        if(u == T) return flow;
        for (; ptr[u] < (int) ke[u].size(); ++ptr[u]) {
            int id = ke[u][ptr[u]], to = e[id].v;
            if(d[to] != d[u] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    int getMaxFlow(int s, int t) {
        S = s, T = t;
        int Flow = 0;
        for (;;) {
            if(!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(int pushed = dfs(S, INF)) {
                Flow += pushed;
            }
        }
        return Flow;
    }
};
void solve()
{
    cin>>n>>m>>s>>t;
    MaxFlow Flow(n);
    FOR(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Flow.addEdge(u,v,w);
    }
    cout<<Flow.getMaxFlow(s,t);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
}
