#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,a[maxn],p[maxn];
struct Fenwick{
    vector<int> t;
    int n;
    void init(int sz)
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
} fw;
int find_pos(int p)
{
    int l = 0, r = n;
    while (r-l > 1)
    {
        int m = l+r >> 1;
        if (m >= fw.get(m) + p)  r = m;
        else l = m;
    }
    return r;
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
    fw.init(n);
    FOR(i,1,n)
    {
        int pos; cin>>pos;
        int new_pos = find_pos(pos);
        cout<<a[new_pos]<<" ";
        fw.update(new_pos,1);
    }    
}
