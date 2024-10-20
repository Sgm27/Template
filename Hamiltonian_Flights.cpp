#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define bit(i,n) (n >> i & 1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7;
#define maxn 20
int n,m,dp[maxn][1 << maxn],edge[maxn][maxn];
vi good_mask;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v; cin>>u>>v;
        edge[--u][--v]++;
    }
    dp[0][1] = 1;
    for (int mask = 1;mask < (1 << n); mask++)
        if (bit(0,mask)) good_mask.push_back(mask);
    for (int mask : good_mask)
    {
        for (int i=1;i<n;i++)
            if (bit(i,mask))
            {
                int pre_mask = mask - (1 << i);
                for (int j=0;j<n;j++)
                    if (bit(j,pre_mask) && edge[j][i]) 
                        (dp[i][mask] += (1LL * dp[j][pre_mask] * edge[j][i]) % MOD) %= MOD;
            }
    }
    cout<<dp[n-1][(1<<n) - 1];
}