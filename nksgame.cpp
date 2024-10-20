#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,a[maxn],b[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans=INT_MAX;
    for (int i=1;i<=n;i++)
    {
        int idx=upper_bound(b+1,b+1+n,-a[i])-b-1;
        ans=min(ans,abs(a[i]+b[idx]));
    }
    cout<<ans;
}

