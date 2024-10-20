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
#define maxn 10005
int n,k,a[maxn];
int dp[maxn][1005];
int get(int idx,int cnt)
{
    if (idx == n + 1) return 0;
    if (dp[idx][cnt] != -1) 
        return dp[idx][cnt];
    int res = 0;
    if (cnt != k-1) 
        res = max(res, a[idx] + get(idx + 1, cnt + 1));
    res = max(res, get(idx + 1, 0));
    return dp[idx][cnt] = res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    memset(dp, -1, sizeof dp);
    FOR(i,1,n) cin>>a[i];
    cout<<get(1,0); 
}
