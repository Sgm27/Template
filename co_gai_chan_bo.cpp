#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
#define bit(n,i) ((n>>i)&1)
int dp[31][32],m,n;
bool check(int mask,int pre_mask)
{
    for (int i=0;i<n-1;i++)
    {
        int sum=0;
        sum+=bit(mask,i);
        sum+=bit(mask,i+1);
        sum+=bit(pre_mask,i);
        sum+=bit(pre_mask,i+1);
        if (sum%4==0) return false; 
    }
    return true;
}
void process()
{
    if (n>m) swap(n,m);
    for (int mask=0;mask<(1<<n);mask++) dp[1][mask]=1;
    for (int i=2;i<=m;i++)
    {
        for (int mask=0;mask<(1<<n);mask++)
        {
            dp[i][mask]=0;
            for (int pre_mask=0;pre_mask<(1<<n);pre_mask++)
                if (check(mask,pre_mask))   
                    dp[i][mask]+=dp[i-1][pre_mask];
        }
    }
    int ans=0;
    for (int mask=0;mask<(1<<n);mask++) 
        ans+=dp[m][mask];
    cout<<ans<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;	
        process();
    }
}

