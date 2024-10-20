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
#define maxn 1000000
int fact[maxn+5],inv_fact[maxn+5];
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
void init()
{
    fact[0] = 1;
    FOR(i,1,maxn)
    {
        fact[i] = (fact[i-1] * i) %MOD;
        inv_fact[i] = Pow(fact[i], MOD-2);
    }
}
int calc(int n,int k)
{
    if (k == 0) return 1;
    int ans = (fact[n] * inv_fact[k]) %MOD;
    return (ans * inv_fact[n-k]) %MOD;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        cout<<calc(n,k)<<"\n";	
    }
}