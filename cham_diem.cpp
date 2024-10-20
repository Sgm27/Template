#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 25
int n,s,k;
int a[maxn][maxn];
int f[205][maxn],g[205][maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>k>>n;
    FOR(i,1,n)
        FOR(j,1,k) cin>>a[i][j];
    f[0][0] = 1;
    FOR(i,0,200)
        FOR(j,0,k) g[i][j] = INF;
    g[0][0] = 0;
    FOR(j,1,k)
    {
        FOR(i,1,n)
            FOD(ss,s,a[i][j]) 
                if (f[ss - a[i][j]][j-1] && (g[ss - a[i][j]][j-1] == INF || a[i][j] >= g[ss - a[i][j]][j-1])) 
                {
                    f[ss][j] = 1;
                    g[ss][j] = min(g[ss][j], a[i][j]);
                }
    }
    if (f[s][k]) 
    {
        vector<int> ans;
        int ss = s, kk = k;
        while (kk)
        {
            ans.push_back(g[ss][kk]);
            ss -= g[ss][kk];
            kk--;
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES\n";
        for (int x : ans) cout<<x<<" ";
    }
    else cout<<"NO";
}
