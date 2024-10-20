#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n;
ll sum[maxn],Max[maxn];
struct mang{
    int gt,cs;
};
mang a[maxn];
bool cmp(mang a,mang b)
{
    if (a.gt!=b.gt) return a.gt<b.gt;
    return a.cs<b.cs;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].gt;
        sum[i]=sum[i-1]+a[i].gt;
        a[i].cs=i;
    }
    sort(a+1,a+1+n,cmp);
    // for (int i=1;i<=n;i++) cout<<a[i].gt<<" "<<a[i].cs<<"\n";
    Max[n]=sum[a[n].cs];
    for (int i=n-1;i>=1;i--)
        if (a[i].gt==a[i+1].gt) Max[i]=max(sum[a[i].cs],Max[i+1]);
        else Max[i]=sum[a[i].cs];
    // for (int i=1;i<=n;i++) cout<<Max[i]<<" ";
    ll ans=-1e18;
    for (int i=1;i<n;i++)
        if (a[i].gt==a[i+1].gt) ans=max(ans,Max[i+1]-sum[a[i].cs-1]);
    cout<<ans;
}

