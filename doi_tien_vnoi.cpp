#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 105
int n,S;
int a[maxn],f[100005];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>S;
    int Max = 0, val = 0;
    FOR(i,1,n) cin>>a[i], Max = max(Max, a[i]);
    if (S > 1e5)
    {
        val = (S - 1e5) / Max + 1;
        S -= val * Max;
    }
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    FOR(i,1,n)
        FOR(j,a[i],S)
            f[j] = min(f[j] , f[j-a[i]] + 1);
    cout<<f[S] + val;  
}
