#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
using ld = long double;
int n;
int d1[8]={40,35,30,25,20,15,10,5};
int d2[8]={0,5,10,15,20,25,30,35};
map<pii,ld> dp;
ld calc(int n,int m)
{
    if (n<=0 && m<=0) return 0.0;
    if (n<=0) return 1.0;
    if (m<=0) return 0.0;
    if (dp.find({n,m})!=dp.end()) return dp[{n,m}];
    ld res=0;
    FOR(i,0,7)
        res+=calc(n-d1[i],m-d2[i]);
    dp[{n,m}]=res/8.0;
    return dp[{n,m}];
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
        cin>>n;
        if (n>=7500*2)
        {
            cout<<"1.00000000000\n";
            continue;
        }
        cout<<fixed<<setprecision(11)<<calc(n/2,n/2)<<"\n";
    }
}
