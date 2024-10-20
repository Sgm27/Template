#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 300005 
struct DT{
    int fi,se,idx;
    friend bool operator<(const DT a,const DT b)
    {
        if (a.fi != b.fi) return a.fi<b.fi;
        if (a.se != b.se) return a.se<b.se;
        return a.idx < b.idx;
    }
} a[maxn];
int n,ans[maxn];
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
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>a[i].fi>>a[i].se, a[i].idx = i;
        a[i].fi++, a[i].se++;
    }
    sort(a+1,a+1+n);
    Fenwick fw(100005);
    vector<int> save;
    ans[a[1].idx] = 0;
    fw.update(a[1].se,1);
    save.push_back(a[1].se);
    FOR(i,2,n)
    {
        if (a[i].fi == a[i-1].fi) save.push_back(a[i].se);
        else 
        {
            save.clear();
            save.push_back(a[i].se);
        }
        int equal = upper_bound(save.begin(),save.end(),a[i].se) - lower_bound(save.begin(),save.end(),a[i].se);
        if (equal) equal--;
        ans[a[i].idx] = fw.get(a[i].se) - equal;
        fw.update(a[i].se,1);
    }
    FOR(i,1,n) cout<<ans[i]<<"\n";
}
