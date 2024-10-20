#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
const ll MOD=1e9+7;
ll k,n;
ll Pow(ll a, ll n)
{
    if (!n) return 1;
    if (n==1) return a;
    ll tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>n>>k)
    {
        ll ans=0;
        for (int i=1;i<=n;i++) ans=(ans+Pow(i,k))%MOD;
        cout<<ans<<"\n";
    }
}

