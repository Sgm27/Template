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
#define maxn 600
int dp[20][maxn][maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    int sum = 0;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i], sum += a[i];
    dp[0][0][0] = 1;
    FOR(i,1,n)
        FOD(j,sum,0)
            FOD(k,sum,0)
            {
                if (dp[i-1][j][k]) dp[i][j][k] = 1;
                if (k >= a[i] && dp[i-1][j][k-a[i]]) dp[i][j][k] = 1; 
                if (j >= a[i] && dp[i-1][j-a[i]][k]) dp[i][j][k]=1; 
            }
    set<int> ans;
    FOR(i,0,sum)
        FOR(j,0,sum)
            if (dp[n][i][j])
            {
                int s = sum - i - j;
                if (i == j && i) ans.insert(i);
                if (j == s && j) ans.insert(s);
                if (i == s && i) ans.insert(s);
            }
    cout<<ans.size()<<"\n";
    for (int i : ans) cout<<i<<" ";
}
