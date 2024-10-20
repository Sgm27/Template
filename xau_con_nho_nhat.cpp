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
        string s; cin>>s;	
        set<char> se;
        for (char c : s) se.insert(c);
        int n = s.length();
        s = " " + s;
        int sz = se.size();
        int l = 1, cur_sz = 0, ans = INF;
        vi mark(256, 0);
        FOR(i,1,n)
        {
            mark[s[i]]++;
            if (mark[s[i]] == 1) cur_sz++;
            while (cur_sz == sz)
            {
                mark[s[l]]--;
                if (mark[s[l]] == 0) 
                {
                    cur_sz--;
                    ans = min(ans, i - l + 1);
                }
                l++;
            }
        }
        cout<<ans<<"\n";
    }
}
