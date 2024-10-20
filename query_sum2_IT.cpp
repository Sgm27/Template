#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],q,t[maxn*4],lz[maxn*4];

void build(int id,int l,int r)
{
    if (l==r) return t[id]=a[l], void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void Push(int id,int m,int l,int r)
{
    t[id*2]+=(m-l+1)*lz[id];
    t[id*2+1]+=(r-m)*lz[id];
    lz[id*2]+=lz[id];
    lz[id*2+1]+=lz[id];
    lz[id]=0;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id]+=(r-l+1)*val;
        lz[id]+=val;
        return;
    }
    int m=(l+r)/2;
    if (lz[id]) Push(id,m,l,r);
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    if (lz[id]) Push(id,m,l,r);
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return t1+t2;
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
        int type,u,v,val;
        cin>>type>>u>>v;
        if (type==1)
        {
            cin>>val;
            update(1,1,n,u,v,val);
        }
        else
            cout<<get(1,1,n,u,v)<<"\n";
    }
}
