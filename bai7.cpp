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
    vi cnt(3), x(n);
    vector<vi> ans;
    auto update = [&](int len)
    {
        if (cnt[0] && is_sorted(ALL(cnt)))
        {
            ans.push_back(vi(x.begin(), x.begin() + len));
        }
    };
    function<void(int,int)> Try = [&](int i,int len)
    {
        FOR(j,0,2)
        {
            x[i] = j;
            cnt[j]++;
            if (i == len - 1)
            {
                update(len);
            }
            else 
                Try(i+1,len);
            cnt[j]--;
        }
    };
    FOR(l,3,n)
        Try(0, l);
    sort(ALL(ans), [](vi &a, vi &b)
    {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });
    for (auto it : ans)
    {
        for (int x : it) 
            cout<<(char)('A' + x);
        cout<<"\n";
    }
}
