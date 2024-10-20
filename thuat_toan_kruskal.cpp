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
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stderr);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    struct edge{
        int u,v,w;
    };
    struct DSU
    {
        vector<int> r, sz;
        int n;
        DSU(int _sz)
        {
            n = _sz;
            r.resize(_sz + 1);
            sz.assign(_sz + 1, 1);
            FOR(i, 1, n)
                r[i] = i;
        }
        int get_root(int u)
        {
            if (u == r[u]) return u;
            return r[u] = get_root(r[u]);
        }
        bool join(int u, int v)
        {
            u = get_root(u);
            v = get_root(v);
            if (u == v)
                return 0;
            if (sz[u] < sz[v])
                swap(u, v);
            sz[u] += sz[v];
            sz[v] = 0;
            return r[v] = u, 1;
        }
    };
    vector<edge> edges;
    int n; cin>>n;
    vector<vi> a(n+1, vi(n+1));
    FOR(i,1,n)
        FOR(j,1,n) 
        {
            cin>>a[i][j];
            if (a[i][j] != -1 && a[i][j] != 0) 
            {
                if (i < j) edges.push_back({i,j,a[i][j]});
            }
        }
    sort(ALL(edges), [](edge a, edge b)
    {
        if (a.w != b.w) 
            return a.w < b.w;
        return make_pair(a.u, a.v) < make_pair(b.u, b.v); 
    });
    cout<<"DANH SACH CANH :\n";
    for (auto [u,v,w] : edges) cout<<"("<<u<<","<<v<<")="<<w<<"\n";
    DSU dsu(n);
    int WT = 0;
    vector<pii> ans_edge;
    for (auto [u,v,w] : edges) 
        if (dsu.join(u,v)) 
        {
            WT += w;
            ans_edge.push_back({u,v});
        }
    cout<<"WT = "<<WT<<"\n";
    cout<<"DANH SACH CANH TRONG MST :\n";
    for (auto it : ans_edge) cout<<"("<<it.first<<","<<it.second<<")"<<"\n";
}
