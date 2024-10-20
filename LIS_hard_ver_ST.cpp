#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30004
int n,a[maxn],dp[maxn],t[maxn*4],b[maxn];
void compression()
{
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+1+m,a[i])-b;
}
void update(int id,int l,int r,int p,int val)
{
    if (l>p || r<p) return;
    if (l==r) return t[id]=max(t[id],val), void();
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++) cin>>a[i], b[i]=a[i];
    compression();
    for (int i=1;i<=n;i++)
    {
        dp[i]=get(1,1,n,1,a[i]-1)+1;
        ans=max(ans,dp[i]);
        update(1,1,n,a[i],dp[i]);
    }
    cout<<ans;
}

