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
#define maxn 200005
#define maxbit 18
int n,w[maxn],h[maxn],par[maxn][maxbit+3];
int tin[maxn], tout[maxn], dfs_timer;
int prime[maxn];
vi g[maxn], nt;
vi compress_graph[maxn];
vi pt[maxn];
int sz[maxn],VT_size;
stack<int> st;
int ans;

void dfs(int u)
{
    tin[u] = ++dfs_timer;
    for (int v : g[u])
        if (v != par[u][0])
        {
            h[v] = h[u] + 1;
            par[v][0] = u;
            FOR(i,1,maxbit)
                par[v][i] = par[par[v][i-1]][i-1];
            dfs(v);
        }
    tout[u] = dfs_timer;
}

bool inside(int u,int v)
{
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int getLCA(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit)
        if (delta >> i & 1) u = par[u][i];
    if (u == v) return u;
    FOD(i,maxbit,0)
        if (par[u][i] != par[v][i]) 
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
void eratos()
{
    int N = maxn - 5;
    FOR(i,2,N)
        prime[i] = i;
    FOR(i,2,sqrt(N))
        if (prime[i] == i)
            for (int j=i*i; j<=N; j+=i) prime[j] = i;
    FOR(i,2,N)
        if (prime[i] == i) nt.push_back(i);
}
int C2(int val)
{
    return val * (val - 1) / 2; 
}
int res;
void dfs_sz(int u,int p = -1)
{
    for (int v : compress_graph[u])
    {
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
    if (p != -1)
    {   
        res += (h[u] - h[p]) * (C2(sz[u]) * (VT_size - sz[u]) + sz[u] * C2(VT_size - sz[u]));
        res %= MOD;
    }
}
int max_val = 0;
void solve(vi &a)
{
    if (a.empty()) return;
    VT_size = a.size();
    for (int i : a) sz[i]++;
    sort(ALL(a), [](int &x,int &y)
    {
        return tin[x] < tin[y];
    });
    for (int i=0; i<VT_size-1; i++)
        a.push_back(getLCA(a[i], a[i+1]));
    sort(ALL(a), [](int &x,int &y)
    {
        return tin[x] < tin[y];
    });
    a.resize(unique(ALL(a)) - a.begin());
    deb(a,VT_size)

    st = stack<int>();
    st.push(a.front());
    for (int i=1;i<a.size();i++)
    {
        while (!inside(st.top(), a[i])) st.pop();
        compress_graph[st.top()].push_back(a[i]);
        st.push(a[i]);
    }
    res = 0;
    dfs_sz(a.front());
    ans += res;
    ans %= MOD;
    for (int x : a)
    {
        compress_graph[x].clear();
        sz[x] = 0;
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);  
    eratos();
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>w[i];
        max_val = max(max_val, w[i]);
    }
    FOR(i,1,n)
    {
        while (w[i] != 1)
        {
            int tmp = prime[w[i]];
            while (w[i] % tmp == 0) w[i] /= tmp;
            pt[tmp].push_back(i);
        }
    }
    FOR(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int x : nt) solve(pt[x]);
    cout<<ans;
}       
