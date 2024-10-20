#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int l,r,k,d;
int dp[20][10][20][2],a[20];

int thu(int i,bool gh,int last_dg,int count,int nghia)
{
    if (!i)
    {
        if (nghia && count<=k) return 1;
        return 0;
    }
    if (gh==false && dp[i][last_dg][count][nghia]>=0) 
        return dp[i][last_dg][count][nghia];
    int maxc=gh ? a[i] : 9,res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        int next_cnt=count;
        if (nghia && abs(c-last_dg)<=d) next_cnt++;
        res+=thu(i-1,ghm,c,next_cnt,nghia | (c!=0));
    }
    if (gh==false) dp[i][last_dg][count][nghia]=res;
    return res;
}
int G(int x)
{
    memset(dp,-1,sizeof(dp));
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,a[n],0,0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>l>>r>>d>>k;
    cout<<G(r)-G(l-1);
}
