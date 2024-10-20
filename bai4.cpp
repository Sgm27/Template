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
#define maxn 50
int g[maxn], f[maxn];
void init()
{
    g[0] = 1;
    g[1] = 0;
    f[0] = f[1] = 1;
    FOR(i,2,maxn-1)
    {
        g[i] = g[i-1] + g[i-2];
        f[i] = f[i-1] + f[i-2];
    }
}
int get(int n,int k)
{
    if (k == f[n])
        return g[n];
    if (k <= f[n-1])
        return get(n-1, k);
    else
        return get(n-2, k - f[n-1]) + g[n-1];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;	
        cout<<get(n,k)<<"\n";
    }
}
