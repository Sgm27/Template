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
#define maxn 
struct Node{
    int lower, equal, upper;
    Node()
    {
        // init val for the empty Node
        lower = equal = upper = 0;
    }
};
Node makeNode(int x,int y,int z)
{
    Node ans;
    // assign the value to Node
    ans.lower = x;
    ans.equal = y;
    ans.upper = z;
    return ans;
}
Node Merge(Node l,Node r)
{
    Node ans;
    // combine two Node
    ans.equal = l.equal + r.equal;
    ans.lower = l.lower + r.lower;
    ans.upper = l.upper + r.upper;
    return ans;
}
void add(Node &a,Node b)
{
    a.equal += b.equal;
    a.lower += b.lower;
    a.upper += b.upper;
}
struct Segment_Tree{
    vector<Node> st,lz;
    Segment_Tree (int _sz)
    {
        st.resize(_sz << 2);
        lz.resize(_sz << 2);
    }
    void push_down(int id,int l,int r,int m)
    {
        add(st[id << 1], lz[id]);
        add(st[id << 1 | 1], lz[id]);
        add(lz[id << 1], lz[id]);
        add(lz[id << 1 | 1], lz[id]);
        lz[id] = Node();
    }
    void update(int id,int l,int r,int u,int v,Node x)
    {
        if (l > v || r < u) return;
        if (l >= u  && r <= v)
        {
            add(st[id], x);
            add(lz[id], x);
            return;
        }
        int m = l+r >> 1;
        push_down(id, l, r, m);
        update(id << 1, l, m, u, v, x);
        update(id << 1 | 1, m+1, r, u, v, x);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    Node get(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return Node();
        if (l >= u && r <= v) return st[id];
        int m = l+r >> 1;
        push_down(id, l, r, m);
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
    int n,X,Y,Z; 
    cin>>n>>X>>Y>>Z;
    vi compress;
    vector<pii> a(n+1);
    FOR(i,1,n)
    {
        cin>>a[i].first>>a[i].second;
        compress.push_back(a[i].first);
        compress.push_back(a[i].second);
    }
    sort(ALL(compress));
    compress.resize(unique(ALL(compress)) - compress.begin());
    int N = compress.size() + 5;
    Segment_Tree ST(N);
    auto find_pos = [&](int val) -> int
    {
        return lower_bound(ALL(compress), val) - compress.begin() + 2;
    };
    FOR(i,1,n)
    {
        a[i].first = find_pos(a[i].first);
        a[i].second = find_pos(a[i].second);
        ST.update(1, 1, N, 1, a[i].first - 1, makeNode(1,0,0));
        ST.update(1, 1, N, a[i].first, a[i].second, makeNode(0,1,0));
        ST.update(1, 1, N, a[i].second+1, N, makeNode(0,0,1)); 
    }
    int ans = -INF;
    FOR(i,1,N)
    {
        Node t = ST.get(1,1,N,i,i);
        ans = max(ans, X * t.lower + Y * t.equal + Z * t.upper);
    }
    cout<<ans;
}
