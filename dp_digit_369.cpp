#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 51
int a[maxn],dp[maxn][maxn][maxn][maxn];

int getDP(int i,bool gh,int cnt3,int cnt6,int cnt9)
{
    if (cnt3 > 17 || cnt6 > 17 || cnt9 > 17) return 0;
    if (!i)
    {
        if (cnt3 && cnt3 == cnt6 && cnt6 == cnt9) return 1;
        return 0;
    }
    if (gh == false && dp[i][cnt3][cnt6][cnt9] != -1) 
        return dp[i][cnt3][cnt6][cnt9];
    int maxc = gh ? a[i] : 9, res = 0;
    for (int c = 0;c <= maxc;c++)
    {
        bool ghm = gh & c == maxc;
        res += getDP(i-1,ghm,cnt3 + (c == 3),cnt6 + (c == 6),cnt9 + (c == 9));
        res %= MOD;
    }
    if (gh == false) dp[i][cnt3][cnt6][cnt9] = res;
    return res;
}
int sol(string s)
{
    int n = 0;
    if (s.length() < 3) return 0;
    for (int i = s.length() - 1;i>=0;i--)
        a[++n] = s[i] - '0';
    return getDP(n,true,0,0,0);
}
void dec(string &s)
{
    if (s == "0") 
    {
        s = "-1";
        return;
    }
    int n = s.length() - 1;
    s[n]--;
    while (1)
    {
        if (!isdigit(s[n]))
        {
            s[n] = '9';
            n--;
            s[n]--;
        }
        else break;
    }
    if (s[0] == '0' && s.length() != 1) s.erase(s.begin());
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int tc; cin>>tc;
    while (tc--)
    {
        string l,r;
        cin>>l>>r;	
        dec(l);
        int ans = sol(r) - sol(l);
        if (ans < 0) ans += MOD;
        cout<<ans<<"\n";
    }
}
