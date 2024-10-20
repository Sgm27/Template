#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,lz[maxn*4],q;
struct nodes{
    int off,on;
} t[maxn*4];
nodes Merge(nodes l,nodes r)
{
    return {l.off+r.off,l.on+r.on};
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={1,0}, void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void Push(int id)
{
    swap(t[id*2].off,t[id*2].on);
    swap(t[id*2+1].off,t[id*2+1].on);
    lz[id*2]^=1;
    lz[id*2+1]^=1;
    lz[id]=0;
}
void update(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        swap(t[id].off,t[id].on);
        lz[id]^=1;
        return;
    }
    if (lz[id]) Push(id);
    int m=(l+r)/2;
    update(id*2,l,m,u,v);
    update(id*2+1,m+1,r,u,v);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
nodes get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    if (lz[id]) Push(id);
    int m=(l+r)/2;
    nodes t1=get(id*2,l,m,u,v);
    nodes t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    build(1,1,n);
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type)
            cout<<get(1,1,n,u,v).on<<"\n";
        else
            update(1,1,n,u,v);
    }
}
