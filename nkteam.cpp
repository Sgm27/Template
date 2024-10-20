#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n;
struct DT{
    int x,y,z;
    friend bool operator<(const DT a,const DT b)
    {
        return a.x < b.x;
    }
} a[maxn];
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.assign(n+1,INF);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x] = min(t[x],val);
    }
    int get(int x)
    {
        int ans=INF;
        for (;x>0;x-=x&-x) ans = min(ans,t[x]);
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
    FOR(x,1,n)
    {   
        int idx; cin>>idx;
        a[idx].x = x;
    }
    FOR(y,1,n)
    {   
        int idx; cin>>idx;
        a[idx].y = y;
    }FOR(z,1,n)
    {   
        int idx; cin>>idx;
        a[idx].z = z;
    }
    sort(a+1,a+1+n);
    Fenwick fw(maxn);
    int ans = 0;
    FOR(i,1,n)
    {
        if (fw.get(a[i].y) > a[i].z) ans++;
        fw.update(a[i].y,a[i].z);
    }
    cout<<ans;
}
