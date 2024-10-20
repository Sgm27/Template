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
#define maxn 25 
int N = 1;
int f[maxn];

char get(int n,int k,int b)
{
    deb(n,k,f[k],b)
    if (k == 0)
    {
        if (n == 1)
            return 'a';
        return 'c';
    }
    if (n <= f[k-1])
        return get(n, k-1, b-1);
    else
    if (n > f[k-1] + b)
        return get(n-f[k-1]-b, k-1, b-1);
    else 
    {
        if (n == f[k-1]+1) return 'a';
        return 'c';
    }   
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    f[0] = 3;
    int b = 4;
    while (1)
    {
        f[N] = 2 * f[N - 1] + b;
        if (f[N] > 1e9) break;
        N++;
        b++;
    }
    // deb(N)
    int n; cin>>n;
    cout<<get(n, N, b);
}
