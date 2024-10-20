#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
const ll MOD=1e9+7;
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
    int tc;   cin>>tc;
    while (tc--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<Pow(a,b)<<"\n";
    }
}

