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
    vector<vi> ans;
    vi x(30);
    function<void(int)> Try = [&](int i)
    {
        FOR(j,0,1)
        {
            x[i] = j;
            if (i == n)
            {
                vi cur;
                FOR(ii,1,n) 
                    if (x[ii]) cur.push_back(a[ii]);
                if (cur.size() >= 2 && is_sorted(ALL(cur))) 
                    ans.push_back(cur);
            }
            else 
                Try(i+1);
        }
    };
    Try(1);
    sort(ALL(ans), [](vi &x,vi &y)
    {
        string s1,s2;
        for (int i : x) 
            s1 += to_string(i) + " ";
        for (int i : y) 
            s2 += to_string(i) + " ";
        return s1 < s2;
    });
    for (auto it : ans)
    {
        for (int x : it) cout<<x<<" ";
        cout<<"\n";
    }
}
