#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
struct data{
    int x,y1,y2,type;
    friend bool operator<(const data a,const data b)
    {
        if (a.x != b.x) return a.x<b.x;
        return a.type<b.type;
    }
};
int n;
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
Fenwick fw(1000005);
vector<data> point;
vector<int> compress;
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
    cin>>n;
    int Max = 0;
    FOR(i,1,n) 
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1,y2);
        compress.push_back(y1);
        compress.push_back(y2);
        compress.push_back(y1+1);
        compress.push_back(y2-1);
        if (x1 == x2)
            point.push_back({x1,y1,y2,0});
        if (y1 == y2)
        {
            point.push_back({x1,y1,y2,1});
            point.push_back({x2,y1,y2,-1});
        }
    }
    sort(compress.begin(),compress.end());
    compress.resize(unique(compress.begin(),compress.end())-compress.begin());
    sort(point.begin(),point.end());
    int ans = 0;
    for (auto it : point)
    {
        int y1 = it.y1;
        int y2 = it.y2;
        if (it.type)   
            fw.update(find_pos(y1),it.type);
        else
            ans += fw.get(find_pos(y2-1)) - fw.get(find_pos(y1+1)-1);
    }
    cout<<ans;
}
