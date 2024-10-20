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
int dp[65][65][65][2]; // pos, cnt0, cnt1, valid
vi digit;
int getDP(int i,bool tight,int c0,int c1,bool valid)
{
    if (i == -1)
        return valid & (c0 >= c1);
    if (tight == false && dp[i][c0][c1][valid] != -1)
        return dp[i][c0][c1][valid];
    int res = 0, maxc = tight ? digit[i] : 1;
    for (int c=0; c<=maxc; c++)
    {
        bool new_tight = tight & c == maxc;
        int new_c1 = c1 + (c == 1);
        int new_c0 = c0;
        if (c == 0 && valid) new_c0++;
        res += getDP(i-1, new_tight, new_c0, new_c1, valid | (c != 0));
    }
    if (tight == false)
        dp[i][c0][c1][valid] = res;
    return res;
}
int G(int x)
{
    if (x == 0) return x;
    digit.clear();
    while (x)
    {
        digit.push_back(x % 2);
        x /= 2;
    }
    return getDP(digit.size() - 1, true, 0, 0, false);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int l,r; cin>>l>>r;
    cout<<G(r) - G(l-1);
}
