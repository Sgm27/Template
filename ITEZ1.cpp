#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int t[maxn*4],a[maxn],n,q;
void build(int id,int l,int r)
{
    if (l==r) 
    {
        t[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) 
    {
        t[id]=val;
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}   
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return -1e9;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1) update(1,1,n,u,v);
        else
        cout<<get(1,1,n,u,v)<<"\n";
    }
}

