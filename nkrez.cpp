#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
pii a[maxn];
int n,dp[maxn];
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
        for (;x<=n;x+=x&-x) t[x] = max(t[x], val);
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans = max(ans, t[x]);
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    Fenwick fw(maxn * 3);
    FOR(i,1,n) 
    {
        cin>>a[i].first>>a[i].second;
        a[i].first++;
        a[i].second++;
    }
    sort(a+1,a+1+n);
    int ans = 0;
    FOR(i,1,n)
    {
        dp[i] = fw.get(a[i].first) + a[i].second - a[i].first;
        ans = max(ans,dp[i]);
        fw.update(a[i].second,dp[i]);
    }
    cout<<ans;
}
