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
int m,k;
int dp[65][65]; //pos, cnt1
vi digit;
int getDP(int i,bool tight,int cnt)
{
    if (i == -1)
        return cnt == k;
    if (tight == false && dp[i][cnt] != -1)
        return dp[i][cnt];
    int res = 0, maxc = tight ? digit[i] : 1;
    for (int c=0; c<=maxc; c++)
    {
        bool new_tight = tight & c == maxc;
        res += getDP(i-1, new_tight, cnt + (c == 1));
    }
    if (tight == false)
        dp[i][cnt] = res;
    return res;
}
int G(int x)
{
    digit.clear();
    while (x)
    {
        digit.push_back(x % 2);
        x /= 2;
    }
    return getDP(digit.size() - 1, true, 0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin>>m>>k;
    int l = 0, r = 1e18;
    while (r-l > 1)
    {
        int mid = l+r >> 1;
        if (G(mid * 2) - G(mid) >= m) r = mid;
        else l = mid;
    }
    cout<<r;
}
