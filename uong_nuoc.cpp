#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 20
#define bit(n,i) ((n>>i)&1)
int a[maxn][maxn],n,k,dp[1<<maxn][maxn];
void input()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) cin>>a[i][j];
}
void process()
{
    if (n==k)
    {
        cout<<0;
        return;
    }
    for (int mask=1;mask<(1<<n);mask++)
    {
        if (__builtin_popcount(mask)==1) continue;
        for (int i=0;i<n;i++)
            if (bit(mask,i))
            {
                int pre_mask=mask-(1<<i);
                dp[mask][i]=1e9;
                for (int j=0;j<n;j++)
                    if (bit(pre_mask,j)) 
                        dp[mask][i]=min(dp[mask][i],dp[pre_mask][j]+a[j][i]);
                cout<<dp[mask][i]<<"\n";
            }
    }
    int ans=1e9;
    for (int mask=1;mask<(1<<n);mask++)
    {
        int x=__builtin_popcount(mask);
        if (x==n-k) 
            for (int i=0;i<n;i++) ans=min(ans,dp[mask][i]);
    }
    cout<<ans;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();   
}

