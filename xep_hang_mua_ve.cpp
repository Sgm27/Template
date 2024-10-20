#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 60005
int n,a[maxn],b[maxn],f[2][maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,2,n) cin>>b[i];
    f[1][1] = INF;
    FOR(i,1,n)
    {
        f[0][i] = min(f[0][i-1],f[1][i-1]) + a[i];
        if (i >= 2)
            f[1][i] = min(f[0][i-2],f[1][i-2]) + b[i];
    }
    cout<<min(f[0][n],f[1][n]);
}
