#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n;
vector<int> v;
struct data{
    int x,y,id;
} a[maxn];
struct Fenwick{
    vector<int> t;
    Fenwick(int n)
    {
        t.resize(n*2+5);
    }
    void update(int x)
    {
        for(;x<=n*2;x+=x&-x) t[x]++;
    }
    int get(int x)
    {
        int ans=0;
        for(;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};

void compression()
{
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    FOR(i,1,n)
    {
        a[i].x=lower_bound(v.begin(),v.end(),a[i].x)-v.begin()+1;
        a[i].y=lower_bound(v.begin(),v.end(),a[i].y)-v.begin()+1;
    }
}
bool cmp(data a,data b)
{
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i].x>>a[i].y, a[i].id=i, v.push_back(a[i].x), v.push_back(a[i].y);
    compression();
    Fenwick fw(2*n);
    sort(a+1,a+1+n,cmp);
    vector<int> ans(n+1);
    // FOR(i,1,n) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].id<<"\n";
    FOD(i,n,1)
    {
        ans[a[i].id]=fw.get(a[i].y);
        fw.update(a[i].y);
    }
    FOR(i,1,n) cout<<ans[i]<<"\n";
}
