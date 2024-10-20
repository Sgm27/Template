#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 3005
int n,a[maxn],dp[maxn][maxn][2];
// first 0
// second 1
int getDP(int l,int r,int state)
{
    if (l > r) return 0; 
    if (dp[l][r][state] != -1) return dp[l][r][state];
    int res;
    if (state == 0)
        res = max(a[l] + getDP(l+1,r,1),a[r] + getDP(l,r-1,1));
    if (state == 1)
        res = min(getDP(l+1,r,0) - a[l],getDP(l,r-1,0) - a[r]);
    dp[l][r][state] = res;
    return res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<getDP(1,n,0);
}
