#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 
int l,r,k,a[15];
int dp[11][91][10004];
long long thu(int i,bool gh,int sum,int sodu)
{
    if (!i)
    {
        if (sum%k==0 && sodu==0) return 1;
        return 0;
    }
    if (gh==false && dp[i][sum][sodu]>=0) return dp[i][sum][sodu];
    int maxc=gh ? a[i] : 9;
    long long res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm= gh & c==maxc;
        res+=thu(i-1,ghm,sum+c,(10*sodu+c)%k);
    }
    if (gh==false) dp[i][sum][sodu]=res;
    return res;
}
long long G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0,0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    FOR(i,1,tc)
    {
        cout<<"Case "<<i<<": ";
        cin>>l>>r>>k;
        FOR(i1,1,10)
            FOR(i2,0,90)
                FOR(i3,0,k) dp[i1][i2][i3]=-1;
        cout<<G(r)-G(l-1)<<"\n";
    }
}
