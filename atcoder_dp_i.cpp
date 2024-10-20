#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld=long double;
#define maxn 3003
int n;
ld dp[maxn][maxn],a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++) dp[0][i]=1.0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++) 
        {
            if (i-1>=j) dp[i][j]+=dp[i-1][j]*(1.0-a[i]);
            if (j>=1) dp[i][j]+=dp[i-1][j-1]*a[i];
        }
    ld ans=0;
    for (int i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
    cout<<fixed<<setprecision(10)<<ans;
}

