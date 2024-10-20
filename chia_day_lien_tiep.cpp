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
        int ntest; cin>>ntest;
        int n; cin>>n;
        vi a(n+1);
        int sum = 0;
        vi pf(n+1);
        FOR(i,1,n) cin>>a[i], sum += a[i], pf[i] = pf[i-1] + a[i];
        vi divisor;
        FOR(i,1,sqrt(sum))
            if (sum % i == 0)
            {
                divisor.push_back(i);
                divisor.push_back(sum / i);
            }
        sort(ALL(divisor));
        int ans = -1;
        for (int s : divisor)
        {
            int pos = 0;
            FOR(i,pos+1,n)
            {
                if (pf[i] - pf[pos] == s) pos = i;
                if (pf[i] - pf[pos] > s) break;
            }
            if (pos == n) 
            {
                ans = s;
                break;
            }
        }
        cout<<ntest<<" "<<ans<<"\n";
    }
}
