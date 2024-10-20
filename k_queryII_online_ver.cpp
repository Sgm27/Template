#include<bits/stdc++.h>
using namespace std;
#define f0(i,n) for (int i=0;i<n;i++)
#define f1(i,n) for (int i=1;i<=n;i++)
using ll = long long;
#define maxn 30004
int n,a[maxn];
vector<int> t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) return t[id].push_back(a[l]), void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    merge(t[id*2].begin(),t[id*2].end(),t[id*2+1].begin(),t[id*2+1].end(),back_inserter(t[id]));
}
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r)
    {
        t[id].clear();
        t[id].push_back(val);
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    auto it=lower_bound(t[id].begin(),t[id].end(),a[p]);
    t[id].erase(it);
    int pos=lower_bound(t[id].begin(),t[id].end(),val)-t[id].begin();
    t[id].insert(t[id].begin()+pos,val);
}
int get(int id,int l,int r,int u,int v,int k)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) 
        return t[id].size()-(upper_bound(t[id].begin(),t[id].end(),k)-t[id].begin());
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v,k);
    int t2=get(id*2+1,m+1,r,u,v,k);
    return t1+t2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    f1(i,n) cin>>a[i];
    build(1,1,n);
    int q; cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type)
        {
            int u,v,k;
            cin>>u>>v>>k;
            cout<<get(1,1,n,u,v,k)<<"\n";
        }
        else
        {
            int p,val;
            cin>>p>>val;
            update(1,1,n,p,val);
            a[p]=val;
        }
    }
}
