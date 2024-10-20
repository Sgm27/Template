#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
using ld = long double;
const int MOD=1e9+7,INF=4e18;
#define maxn 300005
int n,q,in[maxn],out[maxn];
vector<int> adj[maxn];
ld MAX_LOG = log2(1e9),val[maxn];
struct Fenwick{
    vector<ld> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.assign(n+1,0);
    }
    void update(int x,ld val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    ld get(int x)
    {
        ld ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
    ld subTree(int x)
    {
        return get(out[x]) - get(in[x] - 1);
    }
};
int timer = 0;
void dfs(int u,int par)
{
    in[u] = ++timer;
    for (int v : adj[u])
        if (v != par) dfs(v,u);
    out[u] = timer;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    Fenwick fw(n);
    cin>>q;
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type == 1)
        {
            ld new_val = log2(v);
            fw.update(in[u],new_val - val[u]);
            val[u] = new_val;
        }
        else
        {
            ld par = fw.subTree(u), child = fw.subTree(v);
            cout<<fixed<<setprecision(10)<<pow(2.0,min(par - child,MAX_LOG))<<"\n";
        }
    }
}
