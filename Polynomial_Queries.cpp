#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,q,a[maxn];
int t[maxn*4],lz[2][maxn*4];
int val(int n)
{
    return n*(n+1)/2;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]=a[l], void();
    int m=l+r >> 1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void Push(int id,int l,int r,int m)
{
    if (lz[0][id])
    {
        t[id*2] += val(m-l+1)*lz[0][id];
        lz[0][id*2] += lz[0][id];
        t[id*2+1] += (val(r-l+1)-val(m-l+1))*lz[0][id];
        lz[0][id*2+1] += lz[0][id];
        lz[1][id*2+1] += (m-l+1) * lz[0][id];
        lz[0][id]=0;
    }
    if (lz[1][id])
    {
        t[id*2] += (m-l+1)*lz[1][id];
        lz[1][id*2] += lz[1][id];
        t[id*2+1] += (r-m)*lz[1][id];
        lz[1][id*2+1] += lz[1][id];
        lz[1][id]=0;
    }
}
void update(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        t[id] += val(r-u+1)-val(l-u);
        lz[0][id]++;
        lz[1][id] += l-u;
        return;
    }
    int m=l+r >> 1;
    Push(id,l,r,m);
    update(id*2,l,m,u,v);
    update(id*2+1,m+1,r,u,v);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=l+r >> 1;
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
            update(1,1,n,u,v);
        else
            cout<<get(1,1,n,u,v)<<"\n";
    }
}
