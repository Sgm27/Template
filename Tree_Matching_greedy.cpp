#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,mark[maxn],ans;
vector<int> adj[maxn];
void dfs(int u,int par)
{
    for (int v : adj[u])
        if (v != par)
        {
            dfs(v,u);
            if (!mark[u] && !mark[v])
            {
                mark[v] = mark[u] = 1;
                ans++;
            }
        }
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
    cout<<ans;
}
