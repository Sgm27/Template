#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000005
int a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,Min=INT_MAX; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],Min=min(Min,a[i]);
    for (int i=1;i<=n;i++) a[i]-=Min;
    int res=0;
    for (int i=1;i<=n;i++) res=__gcd(res,a[i]);
    cout<<res;
}

