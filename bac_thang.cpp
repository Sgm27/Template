#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD=1e9+7;
ll n,k,dp[100005];
void process()
{
    for (int i=1;i<=n;i++) dp[i]=0;
    dp[0]=dp[1]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=k;j++) 
            if (i-j>=0) 
            {
                dp[i]+=dp[i-j];
                dp[i]%=MOD;
            }
    }
    cout<<dp[n]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        process();
    }
}
