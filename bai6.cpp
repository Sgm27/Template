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
const int MOD=1e9+7,INF=4e18, N = 1e5;
#define maxn 100005
int max_prime[maxn];
int pf[maxn];
void eratos()
{
    FOR(i,1,N)
        max_prime[i] = i;
    max_prime[0] = max_prime[1] = 0;
    FOR(i,2,N)
        if (max_prime[i] == i)
            for (int j = i; j <= N;j+=i)
                max_prime[j] = i;
    FOR(i,1,N)
        pf[i] = pf[i-1] + max_prime[i];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r; cin>>l>>r;
        cout<<pf[r] - pf[l-1]<<"\n";
        // FOR(i,l,r) cout<<max_prime[i]<<" ";
        // cout<<"\n";
    }
}
