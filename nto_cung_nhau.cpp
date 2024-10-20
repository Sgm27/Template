#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool nto(ll k)
{
	if (k==2 || k==3) return true;
	if (k<2 || k%2==0 || k%3==0) return false;
	ll i=5;
	while (i<=int(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return false;
		else i+=6;
	}
	return true;
}
ll phiham(ll k)
{
	ll i=2,res=k;
	while (k!=1)
	{
		if (k%i==0)
		{
			while (k%i==0) k/=i;
			res=res-res/i;
		}
		else i++;
	}
	return res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		ll n;
		cin>>n;
		cout<<nto(phiham(n))<<endl;
	}
}
