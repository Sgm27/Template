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
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n = sz + 5;
        t.assign(n, 0);
    }
    void update(int x,int val)
    {
        for (++x; x < n; x += x&-x) t[x] += val;
    }
    int get(int x)
    {
        int ans = 0;
        for (++x; x > 0; x -= x&-x) ans += t[x];
        return ans;
    }
};
int fact[20];
int get_fact(int k)
{
    if (k == 1) 
        return 1;
    if (fact[k] != 0)
        return fact[k];
    int res = k * get_fact(k-1);
    return fact[k] = res;
}
vi find_kth_permutation(int n,int k)
{
    Fenwick fw(n);
    
    auto bs = [&](int l,int r,int x) -> int
    {
        while (l < r)
        {
            int m = l+r >> 1;
            if (fw.get(m) >= x)
                r = m;
            else 
                l = m+1;
        }
        return r;
    };

    vi a(n);
    a[n-1] = k-1;
    for (int i = n-1; i > 0; i--)
    {
        a[i-1] += a[i] / (n - i);
        a[i] %= (n - i);
    }
    a[0] %= n;
    for (int i = 0; i < n; i++) fw.update(i+1, 1);
    for (int i = 0; i < n; i++)
    {
        a[i] = bs(1, n, a[i] + 1) - 1;
        fw.update(a[i] +1, -1);
    }
    for (int i = 0;i < n; i++) a[i]++;
    return a;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        int type; cin>>type;
        if (type == 2)
        {
            int k; cin>>k;
            vi ans = find_kth_permutation(n,k);
            for (int x : ans)
                cout<<x<<" ";
            cout<<"\n";
        }
        else 
        {
            vi nf(n);
            for (int i = 0; i < n; i++) cin>>nf[i];
            int l = 1, r = get_fact(n) + 1;
            while (r-l > 1)
            {
                int m = (l+r) >> 1;
                if (find_kth_permutation(n,m) > nf) r = m;
                else l = m;
            }
            cout<<l<<"\n";
        }
    }
}
