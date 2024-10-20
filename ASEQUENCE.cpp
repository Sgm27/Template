#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
ll n,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=2) return cout<<"YES", 0;
    ll delta=a[2]-a[1];
    for (int i=3;i<=n;i++)
        if (a[i]-a[i-1]!=delta) return cout<<"NO", 0;
    cout<<"YES";
}

