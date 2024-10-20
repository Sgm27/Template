#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool nto(ll k)
{
	if (k==2 || k==3) return true;
	if (k<2 || k%2==0 || k%3==0) return false;
	ll i=5;
	while (i<=(ll)(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return false;
		else i+=6;
	}
	return true;
}
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return true;
	else return false;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	ll tc; cin>>tc;
	while (tc--)
	{
		ll x; cin>>x;
		if (cp(x) && nto(sqrt(x))) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
