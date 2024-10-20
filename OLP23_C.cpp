#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 55
int n,m,k,dp[maxn][maxn][maxn][maxn];
int sum[maxn][maxn],a[maxn][maxn],used[maxn];
int getSum(int x,int y,int u,int v)
{
    return sum[u][v] - sum[x-1][y] - sum[x][y-1] + sum[x-1][y-1];
}
int get(int x,int y,int u,int v)
{
    if (getSum(x,y,u,v) == 0) return 0;
    if (dp[x][y][u][v] != -1) return dp[x][y][u][v];
    int ans = max(u-x+1, v-y+1);
    FOR(xx,x,u-1) 
        ans = min(ans, get(x,y,xx,v) + get(xx+1,y,u,v));
    FOR(yy,y,v-1)
        ans = min(ans, get(x,y,u,yy) + get(x,yy+1,u,v));
    dp[x][y][u][v] = ans;
    return dp[x][y][u][v];
}
vector<int> MatchX,MatchY,adj[maxn];
bool dfs(int u)
{
    if (used[u] == 1) return 0;
    used[u] = 1;
    for (int v : adj[u])
    {
        if (MatchX[v] == 0 || dfs(MatchX[v])) 
        {
            MatchX[v] = u;
            MatchY[u] = v;
            return 1;
        }
    }
    return 0;
}
void sol1()
{
    MatchX.assign(n+1,0), MatchY.assign(n+1,0);
    for (int i = 1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1;i<=n;i++)
        if (MatchY[i] == 0)
        {
            memset(used, 0, sizeof(used));
            ans += dfs(i);
        }
    cout<<ans<<"\n";
}
void sol2()
{
    FOR(i,1,m)
    {
        int x,y; cin>>x>>y;
        a[x][y] = 1;
    }
    FOR(i,1,n)
        FOR(j,1,n) 
            sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    memset(dp, -1 , sizeof(dp));
    cout<<get(1,1,n,n);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k>>n>>m;
    if (k == 1) sol1();
    else sol2();
}
