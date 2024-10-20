//  solution : https://vnspoj.github.io/problems/KMEDIAN.html
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn],x,dp[maxn];
vector<int> compress;
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
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};
int find_pos(int val)
{
    return lower_bound(compress.begin(),compress.end(),val) - compress.begin() + 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>x;
    dp[0] = 0;
    FOR(i,1,n)
    {
        cin>>a[i];
        dp[i] = dp[i-1] + (a[i] >= x);
        compress.push_back(2*dp[i] - i - 1);
        compress.push_back(2*dp[i-1] - i);
    }
    sort(compress.begin(),compress.end());
    compress.resize(unique(compress.begin(),compress.end()) - compress.begin());
    Fenwick fw(compress.size());
    int ans = 0;
    FOR(i,1,n)
    {
        fw.update(find_pos(2 * dp[i-1] - i),1);
        ans += fw.get(find_pos(2 * dp[i] - i - 1));
    }
    cout<<ans;
}
