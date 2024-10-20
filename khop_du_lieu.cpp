#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
ll n,a[maxn],t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) return t[id]=a[l], void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=__gcd(t[id*2],t[id*2+1]);
}
ll get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    ll t1=get(id*2,l,m,u,v);
    ll t2=get(id*2+1,m+1,r,u,v);
    return __gcd(t1,t2);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        a[i]=abs(a[i]-x);
    }
    build(1,1,n);
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<get(1,1,n,u,v)<<"\n";
    }
}

