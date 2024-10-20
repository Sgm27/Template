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
#define maxn 5005
int dp[maxn];
int dp1[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N = 5000;
    FOR(i,1,N) 
    {
        dp[i] = i;
        dp1[i] = i;
    }
    FOR(i,1,N)
        FOR(j,1,i)
        {
            dp1[i] = min(dp1[i], dp1[j] + dp1[i-j] + 2);
        }
    FOR(i,1,N)
        FOR(j,1,i)
        {
            if (i % j == 0) 
                dp[i] = min(dp[i], dp[j] + dp[i / j] + 2);
        }
    FOR(i,1,N)
        FOR(j,1,i)
        {
            dp[i] = min(dp[i], dp[j] + dp[i-j] + 2);
        }
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        cout<<min(dp[n], dp1[n])<<"\n";
    }
}
