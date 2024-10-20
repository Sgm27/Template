#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll tt;
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
ll process(ll n)
{
	ll cnt=0;
	vector<ll> v;
	for (ll i=1;i<=sqrt(n);i++)
		if (n%i==0) 
		{
			v.push_back(i);
			v.push_back(n/i);
		}
	if (cp(n)) v.pop_back();
	for (ll x : v)
		if (x!=1)
		{
			ll tmp=x*(x-1)/2;
			if ((n-tmp)%x==0) cnt++;
		}
	return cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		ll n; 
		cin>>tt>>n;
		cout<<tt<<" "<<process(n)<<endl;
	}
}

