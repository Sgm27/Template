#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
vi d;
void solve(int n)
{
    int idx = 0;
    while (d[idx] <= n) n -= d[idx], idx++;
    deb(n,idx)
    int p = 1;
    FOR(i,1,idx-1) p *= 10;
    int th = n / idx;
    deb(th)
    p += th - (n % idx == 0);
    string s = to_string(p);
    deb(p)
    if (n % idx == 0)
        cout<<s.back()<<"\n";
    else
        cout<<s[n % idx - 1]<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    d.push_back(0);
    d.push_back(9);
    FOR(i,2,18)
        d.push_back(d.back() / (i-1) * 10 * i);
    // deb(d)
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        solve(n);	
    }
}
