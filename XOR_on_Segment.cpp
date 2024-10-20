#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define bit(i,n) ((n >> i) & 1)
#define maxbit 21
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn],q;
struct Segment_Tree{
    vector<int> st,lz;
    void init(int _sz)
    {
        st.assign(_sz << 2, 0);
        lz.assign(_sz << 2, 0);
    }
    void update_point(int id,int l,int r,int pos)
    {
        if (l == r) 
            return st[id] += 1, void();
        int m = l+r >> 1;
        if (pos <= m) 
            update_point(id << 1,l,m,pos);
        else
            update_point(id << 1 | 1,m+1,r,pos);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    void pushDown(int id,int l,int r,int m)
    {
        if (lz[id])
        {
            lz[id << 1] ^= 1;
            lz[id << 1 | 1] ^= 1;
            st[id << 1] = (m - l + 1) - st[id << 1];
            st[id << 1 | 1] = (r - m) - st[id << 1 | 1];
            lz[id] = 0;
        }
    }
    void update_range(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return;
        if (l>=u && r<=v)
        {
            st[id] = (r-l+1) - st[id];
            lz[id] ^= 1;
            return;
        }
        int m = l+r >> 1;
        pushDown(id,l,r,m);
        update_range(id << 1,l,m,u,v);
        update_range(id << 1 | 1,m+1,r,u,v);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return 0;
        if (l >= u && r <= v) return st[id];
        int m = l+r >> 1;
        pushDown(id,l,r,m);
        return get(id << 1,l,m,u,v) + get(id << 1 | 1,m+1,r,u,v);
    }
} ST[maxbit + 2];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,0,maxbit) ST[i].init(n);
    FOR(i,1,n) 
    {
        cin>>a[i];
        for (int j = 0;j <= maxbit; j++)
            if (bit(j, a[i])) ST[j].update_point(1,1,n,i);
    }
    cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int u,v; cin>>u>>v;
            long long ans = 0;
            FOR(i,0,maxbit)
            {
                int cnt = ST[i].get(1,1,n,u,v);
                ans += 1LL * cnt * (1 << i);
            }
            cout<<ans<<"\n";
        }
        else
        {
            int u,v,x;
            cin>>u>>v>>x;
            FOR(i,0,maxbit)
                if (bit(i,x)) ST[i].update_range(1,1,n,u,v);
        }
    }
}
