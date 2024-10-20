#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int a[10],dp[10][1025][90][2],sum;

int thu(int i,bool gh,int mask,int s,int nghia)
{
    if (i<0)
    {
        if (s==sum) return 1;
        return 0;
    }
    if (gh==false && dp[i][mask][s][nghia]>=0)
        return dp[i][mask][s][nghia];
    int res=0;
    if (gh)
    {
        if (nghia)
        {
            bool ghm=(a[i]==0);
            if ((mask&1)==0) res+=thu(i-1,ghm,mask|1,s,true);
        }
        else
        {
            bool ghm=(a[i]==0);
            res+=thu(i-1,ghm,mask,s,false);
        }
        for (int c=1;c<=a[i];c++)
        {
            bool ghm=(a[i]==c);
            if ((mask&(1<<c)==0)) res+=thu(i-1,ghm,mask|(1<<c),s+c,true);
        }
    }
    else
    {
        if (nghia)
        {
            if ((mask&1)==0) res+=thu(i-1,false,mask|1,)
        }
    }
}
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0,0,false);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int l,r;
    memset(dp,-1,sizeof(dp));
    cin>>l>>r>>sum;
    int ans=G(r)-G(l-1);
}
