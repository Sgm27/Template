#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 50005
const int imin=-1e9;
int n,q,a[maxn];
struct node{
    int pre,suf,sum,maxsum;
};
node t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) 
    {
        t[id]={a[l],a[l],a[l],a[l]};
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].pre=max(t[id*2].pre,t[id*2].sum+t[id*2+1].pre);
    t[id].suf=max(t[id*2+1].suf,t[id*2].suf+t[id*2+1].sum);
    t[id].sum=t[id*2].sum+t[id*2+1].sum;
    t[id].maxsum=max({t[id*2].maxsum,t[id*2+1].maxsum,t[id*2].suf+t[id*2+1].pre});
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {imin,imin,0,imin};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    node tmp;
    tmp.pre=max(t1.pre,t1.sum+t2.pre);
    tmp.suf=max(t2.suf,t1.suf+t2.sum);
    tmp.sum=t1.sum+t2.sum;
    tmp.maxsum=max({t1.maxsum,t2.maxsum,t1.suf+t2.pre});
    return tmp;
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
        int x,y;
        cin>>x>>y;
        cout<<get(1,1,n,x,y).maxsum<<"\n";
    }
}

