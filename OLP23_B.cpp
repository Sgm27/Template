#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
string s,t;
void sol(string s,string t)
{
    int cnt1s = 0, cnt1t = 0;
    FOR(i,0,s.length() - 1)
    {
        if (s[i] == '1') cnt1s++;
        if (t[i] == '1') cnt1t++;
    }
    if (cnt1s > cnt1t) return cout<<"-1\n", void();
    int cnt_char = 0, cnt01 = 0, cnt10 = 0;
    FOR(i,0,s.size() - 1) 
    {
        if (s[i] == '0' && t[i] == '1') cnt01++;
        if (s[i] == '1' && t[i] == '0') cnt10++;
        if (s[i] == '?') cnt_char++;
    }
    int ans = cnt_char;
    if (cnt10 < cnt01)
    {
        ans += cnt10;
        cnt01 -= cnt10;
        ans += cnt01;
        return cout<<ans<<"\n", void();
    }
    else
    {
        ans += cnt01;
        cnt10 -= cnt01;
        ans += cnt10;
        return cout<<ans<<"\n", void();
    }
}
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
        cin>>s>>t;
        sol(s,t);
    }    
}
