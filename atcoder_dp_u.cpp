#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) ((n>>i)&1)
#define set_on(i,n) ((n) | (1<<i))
#define set_off(i,n) ((n) & ~(1<<i)) 
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 16
int n,a[maxn][maxn];
int dp[1<<maxn],val[1<<maxn];
int find_lowest_bit(int mask)
{
    for (int i=0;i<n;i++) 
        if (bit(i,mask)==0) return i;
    return -1;
}
void process()
{
    for (int mask=0;mask<(1<<n);mask++)
    {
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (bit(i,mask)==0 && bit(j,mask)==0)
                {
                    int new_mask=mask | (1<<i) | (1<<j);
                    val[new_mask]+=a[i][j];
                }
    }
    for (int mask=1;mask<(1<<n);mask++)
    {
        dp[mask]=val[mask];
        for (int off_mask=mask&(mask-1);off_mask>0;off_mask=(off_mask-1)&mask)
            dp[mask]=max(dp[mask],dp[mask ^ off_mask]+dp[off_mask]);
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
    cin>>n;
    FOR(i,0,n-1)
        FOR(j,0,n-1) cin>>a[i][j];
    process();
}
