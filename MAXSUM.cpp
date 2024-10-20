#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
#define int long long
#define maxn 100005
int n,a[maxn],l[maxn],r[maxn];
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int sum=0;
    FOR(i,1,n) cin>>a[i], sum+=a[i];
    if (n==1) return cout<<a[1], 0;
    FOR(i,1,n) l[i]=min({l[i-1]+a[i],a[i]});
    FOD(i,n,1) r[i]=min({r[i+1]+a[i],a[i]});
    FOR(i,1,n) l[i]=min(l[i],l[i-1]);
    FOD(i,n,1) r[i]=min(r[i],r[i+1]);
    int ans=-1e18;
    FOR(i,1,n) ans=max(ans,sum-2*(l[i]+r[i+1]));
    cout<<ans;
}
