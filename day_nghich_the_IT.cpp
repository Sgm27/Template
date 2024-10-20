#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 60005
int a[maxn],t[maxn*4],n;
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) return t[id]+=val, void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=t[id*2]+t[id*2+1];
}
ll get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for (int i=n;i>=1;i--)
    {
        ans+=get(1,1,maxn,1,a[i]-1);
        update(1,1,maxn,a[i],1);
    }
    cout<<ans;
}

