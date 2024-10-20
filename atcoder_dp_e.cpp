#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int max_val,n,W,w[maxn],v[maxn];
struct mang{
    int value;
    ll weight=1e18;
} dp[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i], max_val+=v[i];
    dp[0]={1,0};
    for (int i=1;i<=n;i++)
    {
        for (int j=max_val;j>=v[i];j--) 
            if (dp[j-v[i]].value) 
            {
                dp[j].value=1;
                dp[j].weight=min(dp[j].weight,dp[j-v[i]].weight+w[i]);
            }
    }
    for (int i=max_val;i>=0;i--)
    {
        if (dp[i].value && dp[i].weight<=W) 
            return cout<<i, 0;
    }
}

