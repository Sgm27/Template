#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn],f[maxn],g[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i], f[i] = (f[i-1] + a[i]) %MOD, g[i] = f[i];
    FOR(i,1,n)
        f[i] = (f[i-1] + a[i] * g[i-1]) %MOD;
    FOR(i,1,n) g[i] = f[i];
    FOR(i,1,n)
        f[i] = (f[i-1] + a[i] * g[i-1]) %MOD;
    cout<<f[n];
}
