#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 300005
int n,q,c;
pii a[maxn];
struct node{
    int cnt,val;
};
struct Segment_Tree{
    vector<node> t;
    void init(int SZ)
    {
        t.assign(SZ*4,{0,0});
    }
    node Merge(node l,node r)
    {
        node ans;
        if (!l.cnt && !r.cnt) return {0,-1};
        if (!l.cnt) return r;
        if (!r.cnt) return l;
        if (l.val == r.val)
        {
            ans.val=l.val;
            ans.cnt=l.cnt + r.cnt;
        }
        else
        {
            if (l.cnt > r.cnt)
            {
                ans.val=l.val;
                ans.cnt=l.cnt - r.cnt;
            }
            else
            {
                ans.val=r.val;
                ans.cnt=r.cnt - l.cnt;
            }
        }
        return ans;
    }
    void build(int id,int l,int r)
    {
        if (l==r) return t[id]={1,a[l].first}, void();
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id] = Merge(t[id << 1],t[id << 1 | 1]);
    }
    node get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return {0,-1};
        if (l>=u && r<=v) return t[id];
        int m = l+r >> 1;
        node L=get(id << 1,l,m,u,v);
        node R=get(id << 1 | 1,m+1,r,u,v);
        return Merge(L,R);  
    }
} ST;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.ans","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>c;
    ST.init(n);
    FOR(i,1,n)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    ST.build(1,1,n);
    sort(a+1,a+1+n);
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        node diff = ST.get(1,1,n,l,r);
        if (!diff.cnt) 
        {
            cout<<"no\n";
            continue;
        }
        int fre = upper_bound(a+1,a+1+n,(pii){diff.val,r}) - lower_bound(a+1,a+1+n,(pii){diff.val,l});
        if (2 * fre > r - l + 1) cout<<"yes "<<diff.val<<"\n";
        else cout<<"no\n";
    }
}
