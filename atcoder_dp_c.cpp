#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,a[maxn],b[maxn],c[maxn],dp[3][maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    dp[0][1]=a[1]; dp[1][1]=b[1]; dp[2][1]=c[1];
    for (int i=2;i<=n;i++)
    {
        dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a[i];
        dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b[i];
        dp[2][i]=max(dp[0][i-1],dp[1][i-1])+c[i];
    }
    cout<<max({dp[0][n],dp[1][n],dp[2][n]});
}

