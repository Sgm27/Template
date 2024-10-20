#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
const int MOD=1e9+7;
int n,m,k,a[maxn],b[maxn];
ll dp[maxn][maxn][15];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for (int i=1;i<=n;i++)  dp[i][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int z=1;z<=k;z++) 
            {
                dp[i][j][z]=dp[i-1][j][z]+dp[i][j-1][z]-dp[i-1][j-1][z];
                if (a[i]>b[j])  dp[i][j][z]+=dp[i-1][j-1][z-1];
                dp[i][j][z]%=MOD;
            }
    cout<<dp[n][m][k];
}

