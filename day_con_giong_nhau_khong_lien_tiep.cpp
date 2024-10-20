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
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi a(n+1), b(m+1);
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) cin>>b[i];
    vector<vi> dp(n+1, vi(m+1, 0)), dp_prefix(n+1, vi(m+1, 0));
    FOR(i,1,n)
        FOR(j,1,m)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1;
                dp[i][j] += dp_prefix[i-1][j-1];
                dp[i][j] %= MOD;
            }
            dp_prefix[i][j] = dp[i][j] + dp_prefix[i-1][j] + dp_prefix[i][j-1] - dp_prefix[i-1][j-1];
            dp_prefix[i][j] = (dp_prefix[i][j] + MOD*MOD) %MOD;
        }
    cout<<(dp_prefix[n][m] + 1) %MOD;
}
