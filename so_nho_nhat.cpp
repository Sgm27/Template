#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a ,ll b)
{
	return a*b/gcd(a,b);
}
ll mu(ll k)
{
	ll s=1;
	for (int i=1;i<k;i++) s*=10;
	return s;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		ll x,y,z,n;
		cin>>x>>y>>z>>n;
		if (n==0) 
		{
			cout<<"-1\n";
			continue;
		}
		ll bcnn=lcm(x,lcm(y,z));
		ll m=mu(n);
		ll end=mu(n+1);
		if (m%bcnn==0) cout<<m<<endl;
		else 
		{
			ll t=bcnn*(m/bcnn+1);
			if (t<end) cout<<t<<endl;
			else cout<<"-1\n";
		}
	}
}
