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
struct DynamicDisjointSet{
    unordered_map<int, int> root, sz;
    int N;
    
	DynamicDisjointSet() {}

    DynamicDisjointSet(int n){ 
		N = n; 
	}

    int get_root(int vertex)
    {
        if (root.find(vertex) != root.end()) {
 
            if (root[vertex] != vertex) 
            {
                root[vertex] = get_root(root[vertex]);
                return root[vertex];
            }
        }
        else 
        {
            root.insert(make_pair(vertex, vertex));
            sz.insert(make_pair(vertex, 1));
        }
 
        return vertex;
    }
 
    // Union by Rank
    bool join(int u, int v)
    {
        int x = get_root(u);
        int y = get_root(v);
        if (x == y) return false;
        if (sz[x] > sz[y]) 
        {
            root[y] = x;
            sz[x] = sz[x] + sz[y];
        }
        else {
            root[x] = y;
            sz[y] = sz[y] + sz[x];
        }
        return true;
    }

    int get_sz(int u)
    {
        u = get_root(u);
        return sz[u];
    }

    int GetTotalComponent()
    {
        unordered_set<int> total;
        for (auto itr = root.begin();
            itr != root.end(); itr++) {
            total.insert(get_root(itr->first));
        }
        return N - root.size() + total.size();
    }
};
struct edge{
    int u,v,w;
};
vector<edge> edges;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(ALL(edges), [](edge &a, edge &b)
    {
        return a.w < b.w;
    });
    DynamicDisjointSet dsu(n);
    int ans = 0;
    for (auto [u,v,w] : edges)
    {
        if (dsu.get_root(u) != dsu.get_root(v))
        {
            ans += w;
            dsu.join(u, v);
        }
    }
    cout<<ans;
}
