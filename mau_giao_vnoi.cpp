#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
#define bit(n,i) ((n>>i)&1)
ll dp[1<<20],cnt[1<<20];
int n,a[21][21];
void input()
{
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)  cin>>a[i][j];

}
void process()
{
    cnt[0]=1;
    for (int mask=1;mask<(1<<n);mask++)
    {
        int j=__builtin_popcount(mask)-1;
        for (int i=0;i<n;i++)
            if (bit(mask,i))
        {
            int pre_mask=mask-(1<<i);
            if (dp[mask]<dp[pre_mask]+a[j][i])
            {
                dp[mask]=dp[pre_mask]+a[j][i];
                cnt[mask]=cnt[pre_mask];
            }
            else
                if (dp[mask]==dp[pre_mask]+a[j][i])
                    cnt[mask]+=cnt[pre_mask];
        }
    }
    cout<<dp[(1<<n)-1]<<" "<<cnt[(1<<n)-1];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

