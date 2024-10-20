#include <vector>
#include <iostream>
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
#define maxn 20005 
int n,m,low[maxn],id[maxn];
int child[maxn];
int dfs_timer;
vi g[maxn];

void Tarjan(int u,int par = -1)
{
    child[u] += (par != -1);
    low[u] = id[u] = ++dfs_timer;
    for (int v : g[u])
    {
        if (v == par) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= id[u]) child[u]++;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int tplt = 0;
    FOR(i,1,n)
        if (!id[i]) 
        {
            Tarjan(i);
            tplt++;
        }
    FOR(i,1,n) 
        cout<<tplt - 1 + child[i]<<"\n";
}
