#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
struct point{
    int x,y,w;
    friend bool operator<(const point a,const point b)
    {
        if (a.x != b.x) return a.x<b.x;
        if (a.y != b.y) return a.y<b.y;
        return a.w < b.w;
    }
};
point a[maxn];
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.assign(n+1,0);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x] = max(t[x],val);
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans = max(ans,t[x]);
        return ans;
    }
};
int X,Y,n;
vector<point> listPoint;
vector<int> compressY;
int find_pos(int val)
{
    return lower_bound(compressY.begin(),compressY.end(),val) - compressY.begin() + 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>X>>Y>>n;
    FOR(i,1,n)
    {
        cin>>a[i].x>>a[i].y>>a[i].w;
        listPoint.push_back(a[i]);
        compressY.push_back(a[i].y);
    }
    listPoint.push_back({1,1,0});
    listPoint.push_back({X,Y,0});
    compressY.push_back(1);
    compressY.push_back(Y);
    sort(compressY.begin(),compressY.end());
    compressY.resize(unique(compressY.begin(),compressY.end()) - compressY.begin());
    sort(listPoint.begin(),listPoint.end());
    Fenwick fw(compressY.size());
    int ans = 0;
    for (point it : listPoint)
    {
        int y = find_pos(it.y);
        ans = fw.get(y) + it.w;
        fw.update(y,ans);
    }
    cout<<ans;
}
