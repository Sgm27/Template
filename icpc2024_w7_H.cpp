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
    int val;
    Node()
    {
        // init val for the empty Node
        val = INF;
    }
};
Node makeNode(int _val)
{
    Node ans;
    // assign the value to Node
    ans.val = _val;
    return ans;
}
Node Merge(Node l,Node r)
{
    Node ans;
    // combine two Node
    ans.val = min(l.val, r.val);
    return ans;
}
struct Segment_Tree{
    vector<Node> st;
    Segment_Tree (int _sz)
    {
        st.resize(_sz << 2);
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
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        vi a(n+1), b(n+1);
        vector<vi> pos(n+1);
        FOR(i,1,n) 
        {
            cin>>a[i];
            pos[a[i]].push_back(i);
        }
        FOR(i,1,n) cin>>b[i];
        FOR(i,1,n)
        {
            sort(ALL(pos[i]));
            reverse(ALL(pos[i]));
        }
        Segment_Tree ST(n);
        FOR(i,1,n)
            if (pos[i].size()) ST.update(1,1,n,i,pos[i].back());
        bool ans = true;
        FOR(i,1,n)
        {
            if (pos[b[i]].size() == 0) 
            {
                ans = false;
                break;
            }
            int cur_pos = pos[b[i]].back();
            int min_pos = ST.get(1,1,n,1,b[i]-1).val;
            if (min_pos < cur_pos)
            {
                ans = false;
                break;
            }
            pos[b[i]].pop_back();
            if (pos[b[i]].size())
                ST.update(1,1,n,b[i],pos[b[i]].back());
            else 
                ST.update(1,1,n,b[i],INF);
        }
        cout<<(ans ? "YES\n" : "NO\n");
    }
}
