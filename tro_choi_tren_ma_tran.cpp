#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10005
#define bit(n,i) ((n>>i)&1)
int a[8][maxn],n;
bool ok[1<<8];
ll dp[maxn][1<<8],res=-1e9;
void input()
{
    cin>>n;
    for (int i=0;i<8;i++)
        for (int j=1;j<=n;j++) 
        {
            cin>>a[i][j];
            res=max(res,1ll*a[i][j]);
        }
}
void init()
{
    for (int mask=0;mask<(1<<8);mask++)
    {
        ok[mask]=true;
        for (int j=0;j<7;j++)
            if (bit(mask,j) && bit(mask,j+1)) 
            {
                ok[mask]=false;
                break;
            }
    }
}
ll get_sum(int i,int mask)
{
    ll sum=0;
    for (int j=0;j<8;j++)
        if (bit(mask,j)) sum+=a[j][i];
    return sum;
}
void process()
{
    if (res<=0)
    {
        cout<<res;
        return;
    }
    for (int i=1;i<=n;i++)
        for (int mask=0;mask<(1<<8);mask++)
            if (ok[mask])
            {
                ll sum=get_sum(i,mask);
                dp[i][mask]=-1e9;
                for (int pre_mask=0;pre_mask<(1<<8);pre_mask++)
                    if (ok[pre_mask] && (mask&pre_mask)==0) 
                        dp[i][mask]=max(dp[i][mask],dp[i-1][pre_mask]+sum);
            }
    for (int mask=0;mask<(1<<8);mask++)
        if (ok[mask]) res=max(res,dp[n][mask]);
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    init();
    process();
}

