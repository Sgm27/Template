// a^b % m = a^(b % (m-1)) % m
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
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    int div_cnt = 1, div_sum = 1, div_prod = 1;
    int div_cnt2 = 1; // % (MOD - 1)
    while (n--)
    {
        int p,k; cin>>p>>k;
        div_cnt = (div_cnt * (k + 1)) %MOD;
        (div_sum *= ((Pow(p,k+1) - 1 + MOD*MOD) % MOD)) %= MOD;
        (div_sum *= Pow(p-1,MOD-2)) %= MOD;
        div_prod =  (Pow(div_prod, k+1) * Pow(Pow(p, k*(k+1) / 2), div_cnt2)) %MOD;
        div_cnt2 = (div_cnt2 * (k + 1)) % (MOD-1);
    }
    cout<<div_cnt<<" "<<div_sum<<" "<<div_prod;
}
