#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,q,mod,a[maxn];
struct Segment_Tree{
    int st[maxn*4],lz[maxn*4];
    void build(int id,int l,int r)
    {
        if (l==r) return st[id]=a[l]%mod, void();
        int m=(l+r)/2;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=(st[id*2]+st[id*2+1])%mod;
    }
    void Push(int id,int l,int r,int m)
    {
        (st[id*2]+=lz[id]*(m-l+1))%=mod;
        (st[id*2+1]+=lz[id]*(r-m))%=mod;
        (lz[id*2]+=lz[id])%=mod;
        (lz[id*2+1]+=lz[id])%=mod;
        lz[id]=0;
    }
    void update(int id,int l,int r,int u,int v,int val)
    {
        if (r<u || l>v) return;
        if (l>=u && r<=v) 
        {
            (st[id]+=val*(r-l+1))%=mod;
            (lz[id]+=val)%=mod;
            return;
        }
        int m=(l+r)/2;
        if (lz[id]) Push(id,l,r,m);
        update(id*2,l,m,u,v,val);
        update(id*2+1,m+1,r,u,v,val);
        (st[id]=st[id*2]+st[id*2+1])%=mod;
    }
    int get(int id,int l,int r,int u,int v)
    {
        if (r<u || l>v) return 0;
        if (l>=u && r<=v) return st[id];
        int m=(l+r)/2;
        if (lz[id]) Push(id,l,r,m);
        int t1=get(id*2,l,m,u,v);
        int t2=get(id*2+1,m+1,r,u,v);
        return (t1+t2)%mod;
    }
} ST;

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>mod>>n>>q;
    FOR(i,1,n) cin>>a[i];
    ST.build(1,1,n);
    while (q--)
    {
        int type,u,v,val;
        cin>>type>>u>>v;
        if (type==1)
        {
            cin>>val;
            ST.update(1,1,n,u,v,val);
        }
        else
            cout<<ST.get(1,1,n,u,v)<<"\n";
    }
}
