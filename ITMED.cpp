#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,k,a[maxn];
ll t[maxn*4],dp[maxn];
void update(int id,int l,int r,int p,ll val)
{
    if (l>p || r<p) return;
    if (l==r) return t[id]=val, void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
ll get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return -1e18;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    ll res=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        dp[i]=a[i];
        dp[i]=max(dp[i],get(1,1,n,max(1,i-k),i-1)+a[i]);
        update(1,1,n,i,dp[i]);
        res=max(res,dp[i]);
    }
    cout<<res;
}

