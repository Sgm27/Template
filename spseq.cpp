#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn];
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
void compress(int a[])
{
    vector<int> com;
    FOR(i,1,n) com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    FOR(i,1,n)
        a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
}
int dpf[maxn],dps[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    compress(a);
    Fenwick fw1(maxn), fw2(maxn);
    FOR(i,1,n)
    {
        dpf[i] = fw1.get(a[i]-1) + 1;
        fw1.update(a[i],dpf[i]);
    }
    FOD(i,n,1)
    {
        dps[i] = fw2.get(a[i]-1) + 1;
        fw2.update(a[i],dps[i]);
    }
    int ans = 0;
    FOR(i,1,n-1)  
        if (a[i] >= a[i+1])
            ans = max(ans,min(dpf[i],dps[i]) * 2 - 1);
    cout<<max(ans,1LL);
}
