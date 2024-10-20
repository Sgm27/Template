#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 32
int n,k,dp[maxn][maxn][2];
int a[maxn];
int getDP(int i,bool gh,int cnt,bool nghia)
{
    if (!i)
    {
        if (nghia && cnt == k) return 1;
        return 0;
    }
    if (gh == false && dp[i][cnt][nghia] != -1) 
        return dp[i][cnt][nghia];
    int maxc = gh ? a[i] : 1,res = 0;
    for (int c = 0;c <= maxc;c++)
    {
        int new_cnt = cnt;
        bool ghm = gh & c == maxc;
        if (nghia && c == 0) new_cnt++;
        res += getDP(i-1,ghm,new_cnt,nghia | (c != 0));
    }
    if (gh == false) dp[i][cnt][nghia] = res;
    return res;
}
int sol(int x)
{
    memset(dp,-1,sizeof(dp));
    int n = 0;
    while (x)
    {
        a[++n] = x % 2;
        x /= 2;
    }
    return getDP(n,true,0,false);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>n>>k) cout<<sol(n) + (k == 1)<<"\n";
}
