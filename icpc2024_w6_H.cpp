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
const int N = 2e7;
int min_prime[N+5];
vi nt;

inline void eratos()
{
    FOR(i,1,N)
        min_prime[i] = i;
    FOR(i,2,sqrt(N))
        if (min_prime[i] == i)
            for (int j=i*i; j<=N; j+=i) min_prime[j] = i;
    FOR(i,2,N)
        if (min_prime[i] == i) nt.push_back(i);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int n; cin>>n;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    bool check = true;
    if (a[1] == 1) check = false;
    FOR(i,2,n)
    {
        if (a[i] && a[i-1] && __gcd(a[i], a[i-1]) != 1) 
        {
            check = false;
            break;
        } 
        if (a[i] == 0 && a[i-1] == 0)
        {
            check = false;
            break;
        }
        if (a[i] == 1) 
        {
            check = false;
            break;
        }
    }
    if (check == false)
    {
        cout<<"-1";
        return 0;
    }


    set<int> pt;
    int cnt = 0;
    auto add_pt = [&](int val) -> void
    {
        while (val != 1)
        {
            int tmp = min_prime[val];
            pt.insert(tmp);
            while (val % tmp == 0) val /= tmp;  
        }
    };

    FOR(i,1,n)
    {
        if (a[i] == 0)
        {
            cnt++;
            if (i>1) add_pt(a[i-1]);
            if (i<n) add_pt(a[i+1]);
        }
    }
    if (cnt == 0)
    {
        cout<<1;
        return 0;
    }
    int ans = 0;
    for (int i : nt)
        if (pt.count(i) == 0)
        {
            ans = i;
            break;
        }
    cout<<ans;
}
