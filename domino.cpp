#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 100005
int n;
struct data{
    int x,h,id;
} a[maxn];
bool cmp(data a,data b)
{
    return a.x < b.x;
}
struct Segment_Tree{
    vector<int> st;
    Segment_Tree (int SZ)
    {
        st.resize(SZ*4);
    }
    void update(int id,int l,int r,int p,int val)
    {
        if (r<p || l>p) return;
        if (l == r) 
        {
            st[id] = val;
            return;
        }
        int m=(l+r)/2;
        update(id*2,l,m,p,val);
        update(id*2+1,m+1,r,p,val);
        st[id]=max(st[id*2],st[id*2+1]);
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return -1;
        if (l>=u && r<=v) return st[id];
        int m=(l+r)/2;
        int t1=get(id*2,l,m,u,v);
        int t2=get(id*2+1,m+1,r,u,v);
        return max(t1,t2);
    }
};
int save[maxn],ans[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    Segment_Tree ST(n);   
    FOR(i,1,n) cin>>a[i].x>>a[i].h, a[i].id = i;
    sort(a+1,a+1+n,cmp);
    FOD(i,n,1)
    {
        int pos=upper_bound(save+i+1,save+n+1,a[i].x+a[i].h-1) - save - 1;
        save[i] = a[i].x;
        int last = ST.get(1,1,n,i+1,pos);
        if (last == -1) last = i;
        ans[a[i].id] = last - i + 1;
        ST.update(1,1,n,i,last);
    }
    FOR(i,1,n) cout<<ans[i]<<" ";
}
