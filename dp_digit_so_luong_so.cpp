#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 20
int a[maxn],dp[maxn][maxn*9];

int getDP(int i,bool gh,int sum_dg)
{
    if (!i) return (sum_dg == 0);
    if (gh == false && dp[i][sum_dg] != -1)
        return dp[i][sum_dg];
    int maxc = gh ? a[i] : 9, res = 0;
    for (int c = 0;c <= maxc;c++)
    {
        bool ghm = gh & c == maxc;
        if (sum_dg >= c)
            res += getDP(i-1,ghm,sum_dg - c);
    }
    if (gh == false) dp[i][sum_dg] = res;
    return res;
}
int G(int x,int sumDigit)
{
    int n = 0;
    while (x)
    {
        a[++n] = x % 10;
        x /= 10;
    }
    return getDP(n,true,sumDigit);
}
int sol(int n)
{
    int ans = 0;
    for (int i=1;i<=18*9;i++)
    {
        if (i > n) break;
        int lim_of_sumi = n / i;
        ans += G(lim_of_sumi,i);
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r; cin>>l>>r;
        cout<<sol(r) - sol(l-1)<<"\n";
    }
}
