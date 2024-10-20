#include<iostream>
using namespace std;
using ll = long long;
int n,m,dp[10005];
void process()
{
    for (int i=1;i<=n;i++) dp[i]=n-i;
    for (int i=n+1;i<=m+1;i++)
        if (i%2==0)
        {
            dp[i]=dp[i/2]+1;
            if ((i-1)!=n) dp[i-1]=dp[i]+1;
        }
    cout<<dp[m];
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    process();
}

