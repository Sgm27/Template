#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define bit(i,n) ((n>>i)&1)
#define set_on(i,n) ((n) | (1<<i))
#define set_off(i,n) ((n) & ~(1<<i)) 
#define pii pair<int,int>
#define maxn 20
int a[maxn][maxn],n,k;
int dp[1<<maxn];
void process()
{
    memset(dp,27,sizeof(dp));
    for (int mask=0;mask<(1<<n);mask++)
    {
        if (__builtin_popcount(mask)<=k) 
        {
            dp[mask]=0;
            continue;
        }
        for (int i=0;i<n;i++)
        {
            if (!bit(i,mask)) continue;
            for (int j=0;j<n;j++)
            {
                if (!bit(j,mask) || j==i) continue;
                int pre_mask=set_off(i,mask);
                dp[mask]=min(dp[mask],dp[pre_mask]+a[i][j]);
            }
        }
    }
    cout<<dp[(1<<n)-1];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,0,n-1)
        FOR(j,0,n-1) cin>>a[i][j];
    process();
}
