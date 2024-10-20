#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 105
int a[maxn][maxn],f[maxn][maxn],n,m;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n) FOR(j,1,m) cin>>a[i][j];
    FOR(i,0,m) f[0][i] = f[n+1][i] = -INF;
    FOR(i,1,n) f[i][1] = a[i][1];
    FOR(i,2,m)
    {
        FOR(j,1,n) f[j][i] = max({f[j-1][i-1],f[j][i-1],f[j+1][i-1]}) + a[j][i];
    }
    int ans = -INF;
    FOR(i,1,n) ans = max(ans, f[i][m]);
    cout<<ans;
}
