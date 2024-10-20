#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30
int n,S,w[maxn],v[maxn],dp[maxn][30005];
void process()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=S;j++)
            if (j>=w[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
    cout<<dp[n][S];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>S;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) cin>>v[i];
    process();
}

