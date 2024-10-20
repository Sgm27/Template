#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9,INF=4e18;
#define maxn 105
int n,m,a[maxn][maxn],f[maxn][maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)  FOR(j,1,m) cin>>a[i][j];
    FOR(i,1,n) f[i][1] = 1;
    FOR(i,1,n)  FOR(j,1,m)
        FOR(x,1,i)  FOR(y,1,j)
                if (y < m && x+y < i+j && __gcd(a[x][y],a[i][j]) != 1)   
                    (f[i][j] += f[x][y]) %= MOD;
    int ans = 0;
    FOR(i,1,n)  (ans += f[i][m]) %= MOD;
    cout<<ans;
}
