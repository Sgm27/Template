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
#define maxn 2000006
int n, z[maxn], f[maxn];
void Z(string s)
{
    n = s.length();
    s = " " + s;
    z[1] = 0;
    int l, r = 0;
    FOR(i,2,n)
    {
        int x = 0;
        if (i <= r) 
            x = min(z[i-l+1], r-i+1);
        while (i+x <= n && s[x+1] == s[i+x]) x++;
        z[i] = x;
        f[z[i]]++;
        if (r < i+x-1)
        {
            r = i+x-1;
            l = i;
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s,t; cin>>s>>t;
    string str = t + "*" + s;
    Z(str);
    f[n+1] = 1;
    FOD(i,n,1)
        f[i] += f[i+1];
    int ans = 0;
    FOR(i,t.length()+1,n)
        if (z[i] == t.length()) ans++;
    cout<<ans;
}
