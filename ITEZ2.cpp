#include<iostream>
using namespace std;
using ll = long long;
#define maxn 100005
ll t[maxn*4],a[maxn],n,q;
void update(int id,int l,int r,int p)
{
    if (l>p || r<p) return;
    if (l==r) 
    {
        t[id]=a[p];
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,p);
    update(id*2+1,mid+1,r,p);
    t[id]=t[id*2]+t[id*2+1];
}
ll get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int mid=(l+r)/2;
    ll t1=get(id*2,l,mid,u,v);
    ll t2=get(id*2+1,mid+1,r,u,v);
    return t1+t2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1) 
        {
            a[u]=v;
            update(1,1,n,u);
        }
        else cout<<get(1,1,n,u,v)<<endl;
    }
}

