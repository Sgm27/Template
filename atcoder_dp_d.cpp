#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,W,v[maxn],w[maxn];
ll dp[105][maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=W;j++) 
        {
            if (j<w[i]) 
            {
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    cout<<dp[n][W];
}

