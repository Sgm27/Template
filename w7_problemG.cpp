#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
int n,a[maxn],k;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        ll ans=0;
        for (int i=1;i<n;i++)
        {
            auto it=lower_bound(a+1+i,a+1+n,k-a[i]);
            if (it!=a+1+n && *it==k-a[i])
                ans+=upper_bound(a+1+i,a+1+n,k-a[i])-it;
        }
        cout<<ans<<"\n";
    }
}

