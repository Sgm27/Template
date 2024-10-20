#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005 
vector<int> adj[maxn];
int n,cnt[maxn];
void dfs(int u,int par)
{
    for (int v : adj[u])
        if (v != par)
        {
            dfs(v,u);
            cnt[u] += cnt[v];
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
    FOR(i,2,n)
    {
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    FOR(i,1,n) cnt[i] = 1;
    dfs(1,-1);
    FOR(i,1,n) cout<<cnt[i] - 1<<" ";
}
