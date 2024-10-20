// bài này đề sai chỉ có tăng chứ không giảm ạ
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
        int n; cin>>n;
        vector<pii> a(n+1);
        FOR(i,1,n) cin>>a[i].first>>a[i].second;
        vector<vi> dp(n+1, vi(3, INF));
        FOR(i,0,2) 
            dp[1][i] = a[i].second * i;
        FOR(i,2,n)
            FOR(s1,0,2)
                FOR(s2,0,2)
                    if (a[i].first + s2 != a[i-1].first + s1) 
                        dp[i][s2] = min(dp[i][s2], dp[i-1][s1] + s2 * a[i].second);
        // deb(dp)
        cout<<*min_element(ALL(dp[n]))<<"\n";
    }
}
