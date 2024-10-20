#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 10004
int nmax,a[maxn],dp[maxn][4];
bool check(string n)
{
    int sum=0;
    for (char c : n)
        sum=(sum+(c-'0')*(c-'0'))%3;
    return sum==0;
}
int thu(int i,bool gh,int tong)
{
    if (!i)
    {
        if (tong==0) return 1;
        return 0;
    }
    if (gh==false && dp[i][tong]>=0) return dp[i][tong];
    int maxc=gh ? a[i] : 9;
    int res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh && c==maxc;
        (res+=thu(i-1,ghm,(tong+c*c)%3))%=MOD;
    }
    if (gh==false) dp[i][tong]=res;
    return res;
}

int G(string n)
{
    nmax=0;
    for (int i=n.length()-1;i>=0;i--)
        a[++nmax]=n[i]-'0';
    return thu(nmax,true,0);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc=1;
    while (tc--)
    {
        memset(dp,-1,sizeof(dp));
        string n;
        cin>>n;
        cout<<G(n)-check(n)<<"\n";	
    }
}
