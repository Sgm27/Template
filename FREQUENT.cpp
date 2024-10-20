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
struct node
{
    int L_cnt,R_cnt;
    int L_val,R_val;
    int answer;
    node ()
    {
        L_cnt=R_cnt=answer=0;
        L_val=R_val=INF;
    }
};
node operator+(node l,node r)
{
    node ans;
    ans.L_val=l.L_val;
    ans.R_val=r.R_val;
    ans.L_cnt=l.L_cnt;
    ans.R_cnt=r.R_cnt;
    ans.answer=max(l.answer,r.answer);
    if (l.L_val == r.L_val) ans.L_cnt=l.L_cnt+r.L_cnt;
    if (l.R_val == r.R_val) ans.R_cnt=l.R_cnt+r.R_cnt;
    if (l.R_val == r.L_val) ans.answer=max(ans.answer,l.R_cnt+r.L_cnt);
    return ans;
}
struct Segment_Tree{
    vector<node> t;
    void init(int SZ)
    {
        t.resize(SZ*4);
    }
    void build(int id,int l,int r)
    {
        if (l==r) 
        {
            node ans;
            ans.L_cnt=ans.R_cnt=ans.answer=1;
            ans.L_val=ans.R_val=a[l];
            return t[id]=ans, void();
        }
        int m=l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    node get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return node();
        if (l>=u && r<=v) return t[id];
        int m=l+r >> 1;
        node L=get(id << 1,l,m,u,v); 
        node R=get(id << 1 | 1,m+1,r,u,v);
        return L + R;
    }
} ST;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin >> n)
    {
        if (!n) return 0;
        ST.init(n);
        cin>>q;
        FOR(i,1,n) cin>>a[i];
        ST.build(1,1,n);
        while (q--)
        {
            int l,r; cin>>l>>r;
            cout<<ST.get(1,1,n,l,r).answer<<"\n";
        }
    }
}
