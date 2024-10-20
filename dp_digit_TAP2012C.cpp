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
#define bit(i,n) (n >> i & 1)
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
int dp[65][2][1 << 10][10]; // i, valid, mask, base
vi digit;
int getDP(int i,bool tight,bool valid,int mask,int base)
{
    if (i == -1)
    {
        if (valid) return 1;
        return 0;
    }
    if (tight == false && dp[i][valid][mask][base] != -1)
        return dp[i][valid][mask][base];
    int res = 0, maxc = tight ? digit[i] : base - 1;
    for (int c = 0; c <= maxc; c++)
    {
        bool new_tight = tight & c == maxc;
        if (c != 0 && !bit(c, mask)) continue;
        if (c == 0 && valid && !bit(c, mask)) continue;
        res += getDP(i-1, new_tight, valid | (c != 0), mask, base);
    }
    if (tight == false)
        dp[i][valid][mask][base] = res;
    return res;
}
int G(int x,int base,int mask)
{
    digit.clear();
    while (x)
    {
        digit.push_back(x % base);
        x /= base;
    }
    return getDP(digit.size() - 1, true, false, mask, base);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int l,r,base;
    string s;
    while (cin>>l>>r>>base>>s)
    {
        if (s == "*") return 0;
        int cur_mask = 0;
        FOR(i,0,s.length()-1)
            if (s[i] == 'S') cur_mask |= (1 << i);
        cout<<G(r, base, cur_mask) - G(l-1, base, cur_mask)<<"\n";
    }
}
