#include<iostream>
#include<set>
using namespace std;
using ll = long long;
#define maxn 50005
int n,q,a[maxn];
set<int> t[maxn*4];
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
    if (l>p || r<p) return;
    if (l==r)
    {
        t[id].clear();
        t[id].insert(val);
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id].erase(a[p]);
    t[id].insert(val);
}
ll get_sum(set<int> s)
{
    ll ans=0;
    for (int x : s) ans+=x;
    return ans;
}
set<int> get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    set<int> s1=get(id*2,l,m,u,v);
    set<int> s2=get(id*2+1,m+1,r,u,v);
    set<int> S=s1;
    for (int x : s2) S.insert(x);
    return S;
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
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1) 
        {
            update(1,1,n,u,v);
            a[u]=v;
        }
        else
        cout<<get(1,1,n,u,v).size()<<" "<<get_sum(get(1,1,n,u,v))<<"\n";
    }
}

