#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,a[maxn],in[maxn],out[maxn],q,timer;
vector<int> adj[maxn];
int t[maxn * 4];
void dfs(int u,int par)
{
    in[u] = ++timer;
    for (int v : adj[u])
        if (v != par) dfs(v,u);
    out[u] = timer;
}
void update(int id,int l,int r,int p,int val)
{
    if (r<p || l>p) return;
    if (l == r)
        return t[id] = val, void();
    int m = l+r >> 1;
    update(id << 1,l,m,p,val);
    update(id << 1 | 1,m+1,r,p,val);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m = l+r >> 1;
    return get(id << 1,l,m,u,v) + get(id << 1 | 1,m+1,r,u,v);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    FOR(i,1,n) update(1,1,n,in[i],a[i]);
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int s,x; cin>>s>>x;
            update(1,1,n,in[s],x);
        }
        else
        {
            int s; cin>>s;
            cout<<get(1,1,n,in[s],out[s])<<"\n";
        }
    }
}
