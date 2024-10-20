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
    int n,k; cin>>n>>k;
    vi a(n+1);
    int pos_one;
    FOR(i,1,n) 
    {
        cin>>a[i];
        if (a[i] == 1)
            pos_one = i;
    }
    int ans = 0;
    if (pos_one - k + 1 >= 1) 
    {
        ans += (pos_one - 1) / (k - 1) + ((pos_one - 1) % (k - 1) != 0); 
    }
    else 
    {
        ans += 1;
        pos_one = k;
    }
    int re = n - pos_one;
    ans += (re / (k - 1) + (re % (k - 1) != 0));
    cout<<ans;
}
