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
int inv2,n;
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
int sum(int n)
{
    n %= MOD;
    return ((n * (n+1)) % MOD * inv2) %MOD;
}
int get_sum(int l,int r)
{
    return (sum(r) - sum(l-1) + MOD * MOD) %MOD;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    inv2 = Pow(2, MOD - 2);
    cin>>n;
    int cur = 1,ans = 0;
    while (1)
    {
        int q = n / cur;
        int nxt = n / q + 1;
        if (nxt > n)
        {
            (ans += get_sum(cur, n) * q) %= MOD;
            break;
        }   
        (ans += (q * get_sum(cur, nxt - 1)) % MOD) %= MOD;
        cur = nxt;
    }
    cout<<ans;
}
