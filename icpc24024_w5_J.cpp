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
    int n; cin>>n;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    int l=1, r=0, ans = 0;
    multiset<int> ms;
    while (r <= n)
    {
        deb(ms)
        if (ms.size() < 3) 
        {
            ++r;
            ms.insert(a[r]);
        }
        if (ms.size() >= 3)
        {
            int val1 = *ms.begin();   
            int val2 = *(++ms.begin());
            int val3 = *ms.rbegin();
            if (val1 + val2 > val3) 
            {
                ans = max(ans, r-l+1);
                r++;
                if (r == n+1) break;
                ms.insert(a[r]);
            }
            else 
            {
                ms.erase(ms.find(a[l]));
                l++;
            }
        }
    }
    cout<<ans;
}
