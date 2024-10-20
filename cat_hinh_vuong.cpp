#include<iostream>
using namespace std;
using ll = long long;
#define maxn 505
int dp[maxn][maxn],n,m;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) dp[i][j]=1e9;
    for (int i=1;i<=n;i++) dp[i][1]=i;
    for (int i=1;i<=m;i++) dp[1][i]=i;
    for (int i=1;i<=min(n,m);i++) dp[i][i]=1;
    for (int i=2;i<=n;i++)
        for (int j=2;j<=m;j++) 
        {
            if (i==j) continue;
            for (int k=1;k<=max(i,j)/2;k++)
            {
                if (2*k<=i) dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]);
                if (2*k<=j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]);
            }
        }
    cout<<dp[n][m];
}

