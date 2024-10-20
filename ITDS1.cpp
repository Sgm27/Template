#include<iostream>
#include<set>
using namespace std;
using ll = long long;
#define maxn 100005
const int inf=1e9;
multiset<int> t[maxn*4];
int n,a[maxn];
void build(int id,int l,int r)
{
    if (l==r)
    {
        t[id].insert(a[l]);
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2];
    for (int x : t[id*2+1]) t[id].insert(x);
}
void update(int id,int l,int r,int p,int val)
{
    if (p>r || p<l) return;
    if (l==r) 
    {
        t[id].clear();
        t[id].insert(val);
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id].erase(t[id].find(a[p]));
    t[id].insert(val);
}
int get(int id,int l,int r,int u,int v,int k)
{
    if (r<u || l>v) return inf;
    if (l>=u && r<=v) 
    {
        auto it=t[id].lower_bound(k);
        if (it!=t[id].end()) return *it;
        return inf;
    }
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v,k);
    int t2=get(id*2+1,m+1,r,u,v,k);
    return min(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
            a[i]=v;
        }
        else
        {
            int u,v,k;
            cin>>u>>v>>k;
            int tmp=get(1,1,n,u,v,k);
            if (tmp!=inf) cout<<tmp<<"\n";
            else cout<<"-1\n";
        }
    }
}

