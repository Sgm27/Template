#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define bit(n,i) ((n>>i)&1)
#define maxn 
int n,k,a[20];
ll dp[20][1<<16];
void input()
{
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
}
void process()
{
    for (int mask=1;mask<(1<<n);mask++)
        for (int i=0;i<n;i++)
            if (bit(mask,i))
            {
                if (__builtin_popcount(mask)==1) dp[i][mask]=1;
                else
                {
                    int pre_mask=mask-(1<<i);
                    for (int j=0;j<n;j++)
                        if (bit(pre_mask,j) && abs(a[i]-a[j])>k)
                            dp[i][mask]+=dp[j][pre_mask];
                }
            }
    ll ans=0;
    for (int i=0;i<n;i++) ans+=dp[i][(1<<n)-1];
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

