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
#define maxn 1005
int n,m;
struct P{
    int x,y;
} a[maxn], b[maxn];
int dp[maxn][maxn][2];
int dist(P a, P b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int get(int i,int j,int state)
{
    if (i == n && j < m) return INF;
    if (i == n && j == m) return 0;
    if (dp[i][j][state] != -1)
        return dp[i][j][state];
    int res = INF;
    if (state == 0)
    {
        if (i < n)
            res = min(res, get(i+1, j, 0) + dist(a[i], a[i+1]));
        if (j < m)
            res = min(res, get(i, j+1, 1) + dist(a[i], b[j+1]));
    }
    if (state == 1)
    {
        if (i < n)
            res = min(res, get(i+1, j, 0) + dist(b[j], a[i+1]));
        if (j < m)
            res = min(res, get(i, j+1, 1) + dist(b[j], b[j+1]));
    }
    return dp[i][j][state] = res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i].x>>a[i].y;
    FOR(i,1,m) cin>>b[i].x>>b[i].y;
    memset(dp, -1, sizeof dp);
    cout<<get(1,0,0);
}
