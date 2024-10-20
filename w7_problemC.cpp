#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
ll mul_mod(ll a,ll b,ll MOD)
{
    ll res=0;
    a%=MOD;
    while (b)
    {
        if (b%2) res=(res+a)%MOD;
        a=(a*2)%MOD;
        b/=2;
    }
    return res;
}
ll Pow(ll a, ll n,ll MOD)
{
    if (!n) return 1;
    if (n==1) return a;
    ll tmp=Pow(a,n/2,MOD);
    tmp=mul_mod(tmp,tmp,MOD);
    if (n%2) tmp=mul_mod(tmp,a,MOD);
    return tmp;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        ll a,n,m;
        cin>>a>>n>>m;
        cout<<Pow(a,n,m)<<"\n";
    }
}

