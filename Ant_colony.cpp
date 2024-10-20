#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18, BLOCK_SZ = 1024;
#define maxn 100005
int n,a[maxn];
struct RMQ{
    int st[18][maxn];
    void make_RMQ()
    {
        FOR(i,1,n) st[0][i]=a[i];
        FOR(i,1,log2(n))
            FOR(j,1,n-(1<<i)+1)
                st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    int getGCD(int l,int r)
    {
        int k = log2(r - l + 1);
        return __gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }
} f;
struct Node{
    int val,cnt;
    Node()
    {
        val = INF, cnt = 0;
    }
};
Node makeNode(int val,int cnt)
{
    Node ans;
    ans.val = val;
    ans.cnt = cnt;
    return ans;
}
Node Merge(Node l,Node r)
{
    if (l.val < r.val) return l;
    if (r.val < l.val) return r;
    return makeNode(l.val, l.cnt + r.cnt);
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
            return st[id] = makeNode(a[l],1), void();
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
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
    f.make_RMQ();
    Segment_Tree ST(n);
    ST.build(1,1,n);
    int q; cin>>q;
    FOR(i,1,q)
    {
        int l,r; cin>>l>>r;
        int val = f.getGCD(l,r);
        Node getMin = ST.get(1,1,n,l,r);
        cout<<(r - l + 1 - (val == getMin.val ? getMin.cnt : 0))<<"\n";
    }
}
