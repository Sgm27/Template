#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 10004
string k;
int d,a[maxn],dp[maxn*2][205];
int thu(int i,bool gh,int sodu)
{
    if (!i) 
    {
        if (sodu==0) return 1;
        return 0;
    }
    if (gh==false && dp[i][sodu]>=0) return dp[i][sodu];
    int maxc=gh ? a[i] : 9,res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        res+=thu(i-1,ghm,(sodu+c)%d);
    }
    res%=MOD;
    if (gh==false) dp[i][sodu]=res;
    return res;
}
int G(string s)
{
    int n=0;
    for (int i=s.length()-1;i>=0;i--)
        a[++n]=s[i]-'0';
    return thu(n,true,0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    int ans=G(k)-1;
    if (ans==-1) ans=MOD-1;
    cout<<ans;
} 
