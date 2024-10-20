#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
int a[maxn][maxn],n,m;
ll dp[maxn][maxn];
bool f(int x)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) dp[i][j]=0;
    dp[1][1]=x+a[1][1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (i==1 && j==1) continue;
            if (dp[i][j-1] && dp[i][j-1]>a[i][j]) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
            if (dp[i-1][j] && dp[i-1][j]>a[i][j]) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]); 
        }
    return dp[n][m]!=0;
}
void process()
{
    int l=a[1][1],r=1e9+5;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)) r=m;
        else l=m;
    }
    cout<<r;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
    process();
}

