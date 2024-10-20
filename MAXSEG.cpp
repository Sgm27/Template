#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define int long long
#define maxn 500006
int a[maxn],p[maxn],n,r[maxn],d[maxn],sz[maxn],lab[maxn],best=-1e18;
int sum[maxn],ans[maxn],maxsum[maxn],pre[maxn],suf[maxn];
int get_root(int u)
{
    if (u==r[u]) return u;
    return r[u]=get_root(r[u]);
}
void join(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    if (u>v) swap(u,v);
    r[v]=u;
    maxsum[u]=max({maxsum[u],maxsum[v],suf[u]+pre[v]});
    pre[u]=max(pre[u],sum[u]+pre[v]);
    suf[u]=max(suf[u]+sum[v],suf[v]);
    sum[u]+=sum[v];
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i], r[i]=i, sum[i]=a[i], maxsum[i]=a[i], pre[i]=a[i], suf[i]=a[i];
    FOR(i,1,n) cin>>p[i];
    FOD(i,n,1)
    {
        d[p[i]]=1;
        if (d[p[i]-1]) join(p[i],p[i]-1);
        if (d[p[i]+1]) join(p[i],p[i]+1);
        best=max(best,maxsum[get_root(p[i])]);
        ans[i]=best;
    }
    FOR(i,1,n) cout<<ans[i]<<"\n";
}
