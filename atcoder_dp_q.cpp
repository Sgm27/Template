#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
int a[maxn],w[maxn],n;
ll dp[maxn],ans;
pair<int,ll> t[maxn*4];
pair<int,ll> Merge(pair<int,ll> l,pair<int,ll> r)
{
    if (l.second>r.second) return l;
    return r;
}
void update(int id,int l,int r,int p,ll val)
{
    if (r<p || l>p) return;
    if (l==r)
    {
        if (t[id].second<val) t[id]={p,val};
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
pair<int,ll> get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    pair<int,ll> t1=get(id*2,l,m,u,v);
    pair<int,ll> t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int j=1;j<=n;j++) cin>>w[j];
    for (int i=1;i<=n;i++)
    {
        dp[i]=w[i];
        pair<int,ll> x=get(1,1,n,1,a[i]);
        dp[i]=max(dp[i],x.second+w[i]);
        update(1,1,n,a[i],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}

