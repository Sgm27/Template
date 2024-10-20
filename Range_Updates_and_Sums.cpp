#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,q,a[maxn],t[maxn*4];
struct Node{
    int add,set;
} lz[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) return void(t[id]=a[l]);
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void Push(int id,int l,int r,int m)
{
    if (lz[id].set)
    {
        lz[id*2].set=lz[id*2+1].set=lz[id].set;
        t[id*2]=(m-l+1)*lz[id].set;
        t[id*2+1]=(r-m)*lz[id].set;
        lz[id*2].add=lz[id*2+1].add=0;
        lz[id].set=0;
    }
    if (lz[id].add)
    {
        if (lz[id*2].set==0) lz[id*2].add += lz[id].add;
        else
        {
            lz[id*2].set += lz[id].add;
            lz[id*2].add=0;
        }
        if (lz[id*2+1].set==0) lz[id*2+1].add += lz[id].add;
        else
        {
            lz[id*2+1].set += lz[id].add;
            lz[id*2+1].add=0;
        }
        t[id*2] += (m-l+1)*lz[id].add;
        t[id*2+1] += (r-m)*lz[id].add;
        lz[id].add = 0;
    }
}
void upd_add(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        t[id] += (r-l+1)*val;
        if (lz[id].set==0) lz[id].add += val;
        else lz[id].set += val;
        return;
    }
    int m=(l+r)/2;
    Push(id,l,r,m);
    upd_add(id*2,l,m,u,v,val);
    upd_add(id*2+1,m+1,r,u,v,val);
    t[id]=t[id*2]+t[id*2+1];
}
void upd_set(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        t[id] = (r-l+1)*val;
        lz[id].set = val;
        lz[id].add = 0;
        return;
    }
    int m=(l+r)/2;
    Push(id,l,r,m);
    upd_set(id*2,l,m,u,v,val);
    upd_set(id*2+1,m+1,r,u,v,val);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    Push(id,l,r,m);
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
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
    build(1,1,n);
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1) 
        {
            int val; cin>>val;
            upd_add(1,1,n,u,v,val);
        }
        else 
        if (type==2)
        {
            int val; cin>>val;
            upd_set(1,1,n,u,v,val);
        }
        else
            cout<<get(1,1,n,u,v)<<"\n";
    }
}
