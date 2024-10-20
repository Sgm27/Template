#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,q,a[maxn],timer;
struct edge{
    int u,v;
} e[maxn];
int sz[maxn],p[maxn],depth[maxn],head[maxn],pos[maxn],d[maxn];
int out[maxn];
vector<int> adj[maxn];
void dfs(int u)
{
    sz[u]=1;
    int idv= 0;
    int maxSize=0;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v==p[u]) continue;
        depth[v]=depth[u]+1;
        p[v]=u;
        dfs(v);
        sz[u]+=sz[v];
        if (sz[v] > maxSize) maxSize=sz[v], idv = i;
    }
    swap(adj[u][0],adj[u][idv]);
}
void hld(int u)
{
    pos[u]=++timer;
    for (int v : adj[u])
    {
        if (p[v]==u)
        {
            if (2*sz[v] >= sz[u]) head[v]=head[u], d[v]=d[u];
            else head[v]=v, d[v]=d[u]+1;
            hld(v);
        }
    }
    out[u]=timer;
}
int t[maxn*4];
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) 
        return t[id]=val ,void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
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
    dfs(1);
    head[1]=1;
    hld(1);
    FOR(i,1,n) update(1,1,n,pos[i],a[i]);
    while (q--)
    {
        int type,s,x;
        cin>>type>>s;
        if (type==1)
        {
            cin>>x;
            a[pos[s]]=x;
            update(1,1,n,pos[s],x);
        }
        else
            cout<<get(1,1,n,pos[s],out[s])<<"\n";
    }
}
