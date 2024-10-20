#include<iostream>
using namespace std;
using ll = long long;
#define maxn 50005
int ma[maxn*4],mi[maxn*4],a[maxn],n,q;
void update(int id,int l,int r,int pos)
{
    if (r<pos || l>pos) return;
    if (l==r)
    {
        ma[id]=mi[id]=a[pos];
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    ma[id]=max(ma[id*2],ma[id*2+1]);
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
int get(int id,int l,int r,int u,int v,string type)
{
    if (r<u || l>v)
    {
        if (type=="max") return -1e9;
        if (type=="min") return 1e9;
    }
    if (u<=l && r<=v)
    {
        if (type=="max") return ma[id];
        if (type=="min") return mi[id];
    }
    int mid=(l+r)/2;
    int t1=get(id*2,l,mid,u,v,type);
    int t2=get(id*2+1,mid+1,r,u,v,type);
    if (type=="max") return max(t1,t2);
    if (type=="min") return min(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        update(1,1,n,i);
    }
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        int get_max=get(1,1,n,u,v,"max");
        int get_min=get(1,1,n,u,v,"min");
        cout<<get_max-get_min<<"\n";
    }
}

