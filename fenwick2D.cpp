#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

struct Fenwick2d{
    int n,m;
    vector<vi> f;

    Fenwick2d(int _n,int _m)
    {
        n = _n + 5;
        m = _m + 5;
        f.assign(n, vi(m, 0));
    }

    void update(int x,int y,int val)
    {
        x++, y++;
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j) 
            {
                f[i][j] += val;
                f[i][j] %= MOD;
            }
    }

    int get(int x,int y)
    {
        x++, y++;
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j) 
            {
                ans += f[i][j];
                ans %= MOD;
            }
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    vi a(n+1), b(m+1);
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) cin>>b[i];
    Fenwick2d fw(n,m);
    vector<vi> dp(n+1, vi(m+1, 0));
    FOR(i,1,n)
        FOR(j,1,m)
            if (a[i] == b[j]) 
            {
                dp[i][j] = 1;
                dp[i][j] += fw.get(i-1, j-1);
                fw.update(i, j, dp[i][j]);
            }
    int ans = 0;
    FOR(i,1,n)
        FOR(j,1,m) ans += dp[i][j];
    cout<<(ans + 1) %MOD;
}
