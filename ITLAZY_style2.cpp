#include<iostream>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],n,q;
ll T[maxn*4],lazy[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) 
    {
        T[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id]=max(T[id*2],T[id*2+1]);
}
void update(int id,int l,int r,int u,int v,int w)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        lazy[id]+=w;
        T[id]+=w;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,w);
    update(id*2+1,mid+1,r,u,v,w);
    T[id]=max(T[id*2],T[id*2+1])+lazy[id];
}
ll get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return -1e18;
    if (l>=u && r<=v) return T[id];
    int mid=(r+l)/2;
    ll t1=get(id*2,l,mid,u,v);
    ll t2=get(id*2+1,mid+1,r,u,v);
    return max(t1,t2)+lazy[id];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            update(1,1,n,u,v,w);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            cout<<get(1,1,n,u,v)<<"\n";
        }
    }
}

