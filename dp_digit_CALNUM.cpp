#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int dp[20][180][1500],a[20];

int thu(int i,bool gh,int tong,int tongbp)
{
    if (!i)
    {
        if (__gcd(tong,tongbp)==1) return 1;
        return 0;
    }
    if (gh==false && dp[i][tong][tongbp]>=0) 
        return dp[i][tong][tongbp];
    int maxc=gh ? a[i] : 9,res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        res+=thu(i-1,ghm,tong+c,tongbp+c*c);
    }
    if (gh==false) dp[i][tong][tongbp]=res;
    return res;
}
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0,0);
}
int calc_num(int x)
{
    int ans=0;
    while (x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; tc=1;
    while (tc--)
    {
        int l,r;
        cin>>l>>r;
        int num=calc_num(r);
        FOR(i,1,num)
            FOR(j,0,num*9) 
                FOR(k,0,num*81) dp[i][j][k]=-1;
        cout<<G(r)-G(l-1)<<"\n";
    }
}
