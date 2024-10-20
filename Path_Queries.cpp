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
int n,a[maxn],q;
int val[maxn],in[maxn],out[maxn],timer;
vector<int> adj[maxn];
struct Segment_tree{
    vector<int> lz,st;
    Segment_tree (int _sz)
    {
        lz.assign(_sz << 2,0);
        st.assign(_sz << 2,0);
    }
    void Push(int id)
    {
        lz[id << 1] += lz[id];
        lz[id << 1 | 1] += lz[id];
        st[id << 1] += lz[id];
        st[id << 1 | 1] += lz[id];
        lz[id] = 0;
    }
    void update(int id,int l,int r,int u,int v,int val)
    {
        if (r < u || l > v) return;
        if (l>=u && r<=v) 
        {
            st[id] += val;
            lz[id] += val;
            return;
        }
        Push(id);
        int m = l+r >> 1;
        update(id << 1,l,m,u,v,val);
        update(id << 1 | 1,m+1,r,u,v,val);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    int get(int id,int l,int r,int pos)
    {
        if (l == r) return st[id];
        Push(id);
        int m = l+r >> 1;
        if (pos <= m) 
            return get(id << 1,l,m,pos);
        else
            return get(id << 1 | 1,m+1,r,pos);
    }
};
void dfs(int u,int par)
{
    in[u] = ++timer;
    val[u] += a[u];
    for (int v : adj[u])
        if (v != par) 
        {
            val[v] += val[u];
            dfs(v,u);
        }
    out[u] = timer;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    Segment_tree ST(n);
    FOR(i,1,n) 
        ST.update(1,1,n,in[i],in[i],val[i]);
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int pos,new_val;
            cin>>pos>>new_val;
            ST.update(1,1,n,in[pos],out[pos], -a[pos] + new_val);
            a[pos] = new_val;
        }
        else
        {
            int pos; cin>>pos;
            cout<<ST.get(1,1,n,in[pos])<<"\n";
        }
    }
}