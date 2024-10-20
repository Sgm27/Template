#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxbit 18
#define maxn 100005
int n,q,h[maxn];
struct ST {
   int par,Max=0; 
} p[maxn][19];
vector<pii> adj[maxn];
struct DSU{
    int r[maxn],n;
    DSU(int sz)
    {
        n=sz;
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    void join(int u,int v,int val)
    {
        int ru=get_root(u);
        int rv=get_root(v);
        if (ru==rv) return;
        adj[u].push_back({v,val});
        adj[v].push_back({u,val});
        return r[ru]=rv, void();
    }
};
void dfs(int u)
{
    for (pii v : adj[u])
        if (v.first!=p[u][0].par)
        {
            h[v.first]=h[u]+1;
            p[v.first][0].par=u;
            p[v.first][0].Max=v.second;
            FOR(i,1,maxbit)
            {
                p[v.first][i].par=p[p[v.first][i-1].par][i-1].par;
                p[v.first][i].Max=max(p[v.first][i-1].Max,p[p[v.first][i-1].par][i-1].Max);
            }
            dfs(v.first);
        }
}
int LCA(int u,int v)
{
    int ans_max=0;
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if ((delta>>i)&1) 
        {
            ans_max=max(ans_max,p[u][i].Max);
            u=p[u][i].par;
        }
    if (u==v) return ans_max;
    FOD(i,maxbit,0)
        if (p[u][i].par!=p[v][i].par)
        {
            ans_max=max({ans_max,p[u][i].Max,p[v][i].Max});
            u=p[u][i].par;
            v=p[v][i].par;
        }
    ans_max=max({ans_max,p[u][0].Max,p[v][0].Max});
    return ans_max;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    vector<pii> Q;
    while (tc--)
    {
        cin>>n>>q;
        DSU dsu(n);
        FOR(i,1,n) adj[i].clear(), h[i]=0;
        Q.clear();
        FOR(i,1,n)
            FOR(j,0,maxbit) p[i][j].par=p[i][j].Max=0;
        FOR(i,1,q)
        {
            int type,u,v;
            cin>>type>>u>>v;
            if (type==1)
                dsu.join(u,v,i);
            else
            {
                if (dsu.get_root(u) != dsu.get_root(v))
                    Q.push_back({0,0});
                else 
                    Q.push_back({u,v});
            }
        }
        FOR(i,1,n)
            if (!p[i][0].par) dfs(i);
        for (pii x : Q)
            if (!x.first && !x.second)
                cout<<"-1\n";
            else cout<<LCA(x.first,x.second)<<"\n";
    }
}
