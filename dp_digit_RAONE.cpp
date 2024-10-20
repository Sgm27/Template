#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
int a[10];
map<pii,int> dp;

int thu(int i,bool gh,int hieu)
{
    if (!i)
    {
        if (hieu==-1) return 1;
        return 0;
    }
    if (gh==false && dp[{i,hieu}]>=0) return dp[{i,hieu}];
    int maxc=gh ? a[i] : 9;
    int res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        if (i%2) res+=thu(i-1,ghm,hieu+c);
        else res+=thu(i-1,ghm,hieu-c);
    }
    if (gh==false) dp[{i,hieu}]=res;
    return res;
}
// 4 16
// 0 0 -> 0 1 -> 0 4 -> 1 4 -> 4 16
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        FOR(i,0,10)
            FOR(j,-90,90) dp[{i,j}]=-1;
        int l,r;
        cin>>l>>r;
        cout<<G(r)-G(l-1)<<"\n";
    }
}
