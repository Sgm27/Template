#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
const int inf=-1e9;
int a[maxn],n,q;
struct node{
    int pre,suf,sum,maxsum;
};
node t[maxn*4];
node Merge(node l,node r)
{
    node res;
    res.maxsum=max({l.maxsum,r.maxsum,l.suf+r.pre});
    res.pre=max(l.pre,l.sum+r.pre);
    res.suf=max(r.suf,l.suf+r.sum);
    res.sum=l.sum+r.sum;
    return res;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={a[l],a[l],a[l],a[l]}, void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) return t[id]={val,val,val,val}, void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {inf,inf,0,inf};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1) 
        {
            int u,v;
            cin>>u>>v;
            cout<<get(1,1,n,u,v).maxsum<<"\n";
        }
        else 
        {
            int p,val;
            cin>>p>>val;
            update(1,1,n,p,val);
        }
    }
}

