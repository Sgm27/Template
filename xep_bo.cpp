#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
#define int long long
#define maxn 1000006
const int MOD=2111992;
int n,m,dp[maxn][2];
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    dp[0][0]=1;
    FOR(i,1,n)
    {
        dp[i][0]+=dp[i-1][0]+dp[i-1][1];
        if (i>m) dp[i][1]+=dp[i-m-1][1]+dp[i-m-1][0];
        else dp[i][1]=1;
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }
    cout<<(dp[n][1]+dp[n][0])%MOD;
}
