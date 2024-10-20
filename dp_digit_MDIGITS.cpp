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
#define maxn 10 
int ans[maxn], dp[maxn][2][maxn][10]; //i, nghia, cnt, cur_digit
int digit[maxn];
int getDP(int i, bool gh, bool nghia, int cnt, int d)
{
    if (!i)
    {
		if (nghia) return cnt;
		return 0;
    }
    if (gh == false && dp[i][nghia][cnt][d] != -1)
        return dp[i][nghia][cnt][d];
    int maxc = gh ? digit[i] : 9, res = 0;
    for (int c = 0; c <= maxc; c++)
    {
        bool ghm = gh & c == maxc;
        int new_cnt = cnt;
        if (nghia) 
            new_cnt += (c == d);
        res += getDP(i-1, ghm, nghia | (c != 0), new_cnt, d);
    }
    if (gh == false) 
        dp[i][nghia][cnt][d] = res;
    return res;
}
void get(int x,int type)
{
    int n = 0;
    while (x)
    {
        digit[++n] = x % 10;
        x /= 10;
    }
    FOR(d,0,9)
        ans[d] += type * getDP(n, true, d != 0, 0, d);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    while (1)
    {
        int l,r; cin>>l>>r;
        if (l == 0 && r == 0) return 0;
        memset(ans, 0, sizeof ans);
		if (l > r) swap(l,r);
        get(r,1);
        get(l-1,-1);
        FOR(i,0,9) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
