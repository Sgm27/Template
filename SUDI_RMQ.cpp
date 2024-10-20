#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn];
int mi[20][maxn], ma[20][maxn];
unordered_map<int,int> trace;
struct Node{
    int val,cnt;
    Node()
    {
        // init val for the empty Node
    }
};
Node makeNode(int _val)
{
    Node ans;
    // assign the value to Node
    return ans;
}
Node Merge(Node l,Node r)
{
    Node ans;
    // combine two Node
    return ans;
}
struct Segment_Tree{
    vector<Node> st;
    Segment_Tree (int _sz)
    {
        st.resize(_sz << 2);
    }
    void build(int id,int l,int r)
    {
        if (l == r) 
            return st[id] = makeNode( ), void(); // base Node
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    void update(int id,int l,int r,int pos,int val)
    {
        if (l > pos || r < pos) return;
        if (l == r) 
            return st[id] = makeNode( ), void(); // base Node
        int m = l+r >> 1;
        update(id << 1,l,m,pos,val);
        update(id << 1 | 1,m+1,r,pos,val);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    Node get(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return Node();
        if (l >= u && r <= v) return st[id];
        int m = l+r >> 1;
        return Merge(get(id << 1,l,m,u,v), get(id << 1 | 1,m+1,r,u,v));
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
    FOR(i,1,n) cin>>a[i];
    RMQ();
    int ans = 0;
    FOR(i,1,n)
    {
        int lmax, rmax;
        int l = trace[a[i]], r = i;
        while (r-l > 1)
        {
            int m = l+r >> 1;
            if (get_max(m, i) == a[i]) r = m;
            else l = m;
        }
        lmax = i - r + 1;
        l = i, r = n+1;
        while (r-l > 1)
        {
            int m = l+r >> 1;
            if (get_max(i, m) == a[i]) l = m;
            else r = m;
        }
        rmax = l - i + 1;
        ans += lmax * rmax * a[i];

        int lmin, rmin;
        l = trace[a[i]], r = i;
        while (r-l > 1)
        {
            int m = l+r >> 1;
            if (get_min(m, i) == a[i]) r = m;
            else l = m;
        }
        lmin = i - r + 1;
        l = i, r = n+1;
        while (r-l > 1)
        {
            int m = l+r >> 1;
            if (get_min(i, m) == a[i]) l = m;
            else r = m;
        }
        rmin = l - i + 1;
        ans -= lmin * rmin * a[i];   
        trace[a[i]] = i;
    }
    cout<<ans;
}
