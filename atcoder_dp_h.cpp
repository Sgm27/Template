#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1003
const int MOD=1e9+7;
int a[maxn][maxn],dp[maxn][maxn],n,m;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char x; cin>>x;
            if (x=='.') a[i][j]=1;
            else a[i][j]=0;
        }
    if (!a[1][1] || !a[n][m]) return cout<<0, 0;
    dp[n][m]=1;
    for (int i=n;i>=1;i--)
        for (int j=m;j>=1;j--)
            if (a[i][j])
        {
            if (i==n && j==m) continue;
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
            dp[i][j]%=MOD;
        }
    cout<<dp[1][1];
}

