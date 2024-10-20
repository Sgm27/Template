#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,q,a[maxn];
struct Segment_Tree{
    vector<int> t;
    void init(int sz)
    {
        t.resize(sz*4,0);
    }
    void build(int id,int l,int r)
    {
        if (l==r) return t[id]=a[l], void();
        int m= l+r >>1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id] = t[id << 1]+ t[id<< 1 | 1];
    }
    void update(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return;
        if (t[id] == r-l+1) return; 
        // all element of node id have modify to 1
        if (l == r) 
        {
            t[id]=(int)sqrt(t[id]);
            return;
        }
        int m=l+r >>1;
        update(id << 1,l,m,u,v);
        update(id << 1 | 1,m+1,r,u,v);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return 0;
        if (l>=u && r<=v) return t[id];
        int m = l+r >> 1;
        return get(id << 1,l,m,u,v)+get(id << 1 | 1,m+1,r,u,v);
    }
} ST;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest=0;
    while (cin >> n && ++ntest)
    {
        cout<<"Case #"<<ntest<<":\n";
        ST.init(n);
        FOR(i,1,n) cin>>a[i];
        ST.build(1,1,n);
        cin>>q;
        while (q--)
        {
            int type,u,v;
            cin>>type>>u>>v;
            if (u>v) swap(u,v);
            if (type == 0)
                ST.update(1,1,n,u,v);
            else
                cout<<ST.get(1,1,n,u,v)<<"\n";
        }
    }
}
