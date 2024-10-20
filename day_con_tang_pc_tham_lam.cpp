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
#define maxn 200005
int n;
pii a[maxn];
struct Node{
    int min_pos;
    Node()
    {
        // init val for the empty Node
        min_pos = 0;
    }
};
Node makeNode(int _pos)
{
    Node ans;
    // assign the value to Node
    ans.min_pos = _pos;
    return ans;
}
Node Merge(Node l,Node r)
{
    Node ans;
    // combine two Node
    if (a[l.min_pos].second < a[r.min_pos].second) ans.min_pos = l.min_pos;
    else ans.min_pos = r.min_pos;
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
            return st[id] = makeNode(l), void(); // base Node
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    void update(int id,int l,int r,int pos,int val)
    {
        if (l > pos || r < pos) return;
        if (l == r) 
            return st[id] = makeNode(val), void(); // base Node
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
    a[0].second = INF;
    FOR(i,1,n)
        cin>>a[i].first, a[i].second = i;
    sort(a+1,a+1+n);
    Segment_Tree ST(n);
    ST.build(1,1,n);
    int sz = n;
    vector<vi> ans;
    vi cur;
    while (sz)
    {
        int pos = ST.get(1,1,n,1,n).min_pos;
        sz--;
        cur.push_back(pos);
        while (sz)
        {
            int nxt_pos = upper_bound(a+1+pos, a+1+n, make_pair(a[pos].first, INF)) - a;
            ST.update(1,1,n,pos,0);
            int tmp = ST.get(1,1,n,nxt_pos,n).min_pos;
            if (tmp == 0) break;
            nxt_pos = tmp;
            cur.push_back(nxt_pos);
            pos = nxt_pos;
            sz--;
        }
        ans.push_back(cur);
        cur.clear();
    }
    cout<<ans.size()<<"\n";
    for (auto it : ans)
    {
        for (int x : it) cout<<a[x].first<<" ";
        cout<<"\n";
    }
}
