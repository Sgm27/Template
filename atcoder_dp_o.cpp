#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1<<21
#define bit(n,i) ((n>>i)&1)
const int MOD=1e9+7;
int n,a[25][25];
ll dp[maxn],cnt[maxn];
void input()
{
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) 
        {
            cin>>a[i][j];
        }
}
void process()
{
    cnt[0]=1;
    for (int mask=1;mask<(1<<n);mask++)
    {
        int k=__builtin_popcount(mask)-1;
        for (int i=0;i<n;i++)
            if (bit(mask,i))
            {
                int pre_mask=mask-(1<<i);
                if (dp[mask]<dp[pre_mask]+a[k][i]) 
                {
                    dp[mask]=dp[pre_mask]+a[k][i];
                    cnt[mask]=cnt[pre_mask];
                }
                else
                if (dp[mask]==dp[pre_mask]+a[k][i])
                {
                    cnt[mask]+=cnt[pre_mask];
                    cnt[mask]%=MOD;
                }
            }
    }
    if (dp[(1<<n)-1]!=n) cout<<0;
    else cout<<cnt[(1<<n)-1];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

