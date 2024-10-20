#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD=123456789;
ll Pow(ll a, ll n)
{
    if(n == 1) {
        return a;
    } else {
        ll temp =Pow(a, n/2 )%MOD;
        if(n % 2 == 0)
            return (temp * temp)%MOD ;
        else
            return (temp * temp * a)%MOD;
    }
}
int main()
{
//	freopen("thu.inp","r",stdin);
	ll x;
	cin>>x;
	cout<<Pow(2,x-1);
}
