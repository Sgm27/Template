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
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("check.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        vi in(n+1), out(n+1);
        DSU dsu(2*n);
        set<pii> edges;
        FOR(i,1,n)
        {
            in[i] = i, out[i] = i+n;
            dsu.join(in[i], out[i]);
            deb(i, in[i], out[i])
        }
        bool ans = false;
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            edges.insert({u,v});
        }
        deb(edges)
        for (auto [u,v] : edges)
            if (!dsu.join(out[u], in[v]))
            {
                deb(u,v,out[u],in[v])
                ans = true;
                break;
            }
            else 
            {
                deb(u,v,out[u],in[v])
            }
        cout<<(ans ? "YES\n" : "NO\n");
    }
}
