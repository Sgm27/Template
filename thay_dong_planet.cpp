#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn],st[18][maxn];
int dp[maxn];
int get(int l,int r)
{
    int t=log2(r-l+1);
    return __gcd(st[t][l],st[t][r-(1<<t)+1]);
}
void make_RMQ(int l,int r)
{
    FOR(i,1,r) st[0][i]=a[i];
    FOR(i,1,log2(r))
        FOR(j,1,r-(1<<i)+1)
            st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) (t[x] += val) %= MOD;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) (ans += t[x]) %= MOD;
        return ans;
    }
};
int getDP(int l,int r)
{
    Fenwick fw(n+1);
    fw.update(1,1);
    FOR(i,l,r)
    {
        int low = l-1, high = i;
        while (high - low > 1)
        {
            int mid = low + high >> 1;
            if (get(mid,i) > 1) high = mid;
            else low = mid;  
        }
        int i_get = i+1, low_get = low + 1;
        dp[i] = (fw.get(i_get-1) - fw.get(low_get-1) + MOD*MOD) %MOD;
        fw.update(i_get,dp[i]); 
    }
    return dp[r];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    a[n+1] = a[1];
    int r = n, ans = 0;
    make_RMQ(1,n);
    (ans += getDP(1,n)) %= MOD;
    while (r >= 1)
    {
        int new_a1 = __gcd(a[1],a[r]);
        if (new_a1 == 1) break;
        if (new_a1 == a[1])
        {
            r--;
            (ans += dp[r]) %= MOD;
            continue;
        }
        a[1] = new_a1;
        r--;
        make_RMQ(1,r);
        (ans += getDP(1,r)) %= MOD;
    }
    cout<<ans;
}
