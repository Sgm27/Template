#include<iostream>
using namespace std;
using ll = long long;
int n,a,b,c,dp[4005];
void process()
{
    for (int i=0;i<=n;i++) dp[i]=0;
    dp[a]=dp[b]=dp[c]=1;
    for (int i=1;i<=n;i++)
    {
        int Max=dp[i],check=0;
        if (i>=a && dp[i-a]) 
        {
            Max=max(Max,dp[i-a]);
            check=1;
        }
        if (i>=b && dp[i-b]) 
        {
            Max=max(Max,dp[i-b]);
            check=1;
        }
        if (i>=c && dp[i-c]) 
        {
            Max=max(Max,dp[i-c]);
            check=1;
        }
        if (check) dp[i]=Max+1;
    }
    cout<<dp[n];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>a>>b>>c;
    process();
}

