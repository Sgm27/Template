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
int t[maxn*4];
struct lazy{
    int add,set,mul=1;
} lz[maxn*4];
int mod(int a,int b)
{
    int res=0;
    a%=MOD;
    while (b)
    {
        if (b%2) res=(res+a)%MOD;
        a=(a*2)%MOD;
        b/=2;
    }
    return res;
}
void build(int id,int l,int r)
{
    if (l==r) return void(t[id]=a[l]);
    int m= l+r >>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=(t[id*2]+t[id*2+1])%MOD;
}
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
void Push(int id,int l,int r,int m)
{
    if (lz[id].set)
    {
        lz[id*2].set=lz[id*2+1].set=lz[id].set;
        t[id*2]=(m-l+1)*lz[id].set;
        t[id*2+1]=(r-m)*lz[id].set;
        lz[id*2].add=lz[id*2+1].add=0;
        lz[id*2].mul=lz[id*2+1].mul=1;
        lz[id].set=0;
    }
    if (lz[id].add)
    {
        if (lz[id*2].set == 0) lz[id*2].add += lz[id].add;
        else
        {
            lz[id*2].set += lz[id].add;
            lz[id*2].add = 0;
        } 
        if (lz[id*2+1].set == 0) lz[id*2+1].add += lz[id].add;
        else
        {
            lz[id*2+1].set += lz[id].add;
            lz[id*2].add = 0;
        }
        t[id*2] += (m-l+1)*lz[id].add;
        t[id*2+1] += 
    }
}
void upd_add(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id] = (t[id] + (r-l+1)*val)%MOD;
        if (lz[id].set == 0) lz[id].add += val;
        else lz[id].set += val;
        return;
    }
    int m = l+r>>1;
    Push(id,l,r,m);
    upd_add(id*2,l,m,u,v,val);
    upd_add(id*2+1,m+1,r,u,v,val);
    t[id]=(t[id*2]+t[id*2+1])%MOD;
}
void upd_mul(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id]=mod(t[id], Pow(val,r-l+1));
        if (lz[id].set == 0)
        {
            (lz[id].mul *= val)%=MOD;
            (lz[id].add = lz[id].add*val)%=MOD;
        }
        else
            (lz[id].set *= val)%=MOD;
        return;
    }
    int m=(l+r)/2;
    Push(id,l,r,m);
    upd_mul(id*2,l,m,u,v,val);
    upd_mul(id*2+1,m+1,r,u,v,val);
    t[id]=(t[id*2]+t[id*2+1])%MOD;
}
void upd_set(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id] = (r-l+1)*val;
        lz[id].set = val;
        lz[id].add = 0;
        lz[id].mul = 1;
        return;
    }
    int m = (l+r)/2;
    Push(id,l,r,m);
    upd_set(id*2,l,m,u,v,val);
    upd_set(id*2+1,m+1,r,u,v,val);
    t[id]=(t[id*2]+t[id*2+1])%MOD;
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m = (l+r)/2;
    Push(id,l,r,m);
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return (t1+t2)%MOD;
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
    while (q--)
    {
        int type; cin>>type;
        if (type == 4)
        {
            int u,v; cin>>u>>v;
            cout<<get(1,1,n,u,v);
        }
        else
        {
            int u,v,val;
            cin>>u>>v>>val;
            if (type==1)
                upd_add(1,1,n,u,v,val);
            if (type==2)
                upd_mul(1,1,n,u,v,val);
            if (type==3)
                upd_set(1,1,n,u,v,val);
        }
    }
}
