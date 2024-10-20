#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
#define maxbit 17
int n,q,h[maxn];
vector<pii> adj[maxn];
struct ST{
    int par,sum;
};
ST p[maxn][maxbit+4];
void dfs(int u)
{
    for (pii x : adj[u])
        if (x.first!=p[u][0].par)
        {
            int v=x.first;
            int w=x.second;
            h[v]=h[u]+1;
            p[v][0].par=u;
            p[v][0].sum=w;
            FOR(i,1,maxbit)
            {
                p[v][i].par=p[p[v][i-1].par][i-1].par;
                p[v][i].sum=p[v][i-1].sum+p[p[v][i-1].par][i-1].sum;
            }
            dfs(v);
        }
}
int LCA(int u,int v)
{
    int Sum=0;
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    FOR(i,0,maxbit)
        if ((delta>>i)&1)
        {
            Sum+=p[u][i].sum;
            u=p[u][i].par;
        }
    if (u==v) return Sum;
    FOD(i,maxbit,0)
        if (p[u][i].par!=p[v][i].par)
        {
            Sum+=p[u][i].sum+p[v][i].sum;
            u=p[u][i].par;
            v=p[v][i].par;
        }
    Sum+=p[u][0].sum+p[v][0].sum;
    return Sum;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>n)
    {
        if (!n) return 0;
        FOR(i,1,n-1)
        {
            int v,w;
            cin>>v>>w;
            adj[i].push_back({v,w});
            adj[v].push_back({i,w});
        }
        dfs(0);
        cin>>q;
        while (q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<LCA(u,v)<<" ";
        }
        FOR(i,0,n) adj[i].clear();
        cout<<"\n";
    }    
}
