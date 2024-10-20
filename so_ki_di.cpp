#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void sang(ll l,ll r)
{
	ll prime[r-l+1];
	for (ll i=0;i<=r-l+1;i++) prime[i]=1;
	for (ll i=2;i<=sqrt(r);i++)
		for (ll j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
			prime[j-l]=0;
	ll cnt=0;
	for (ll i=max(l,1ll*2);i<=r;i++)
		if (prime[i-l]) cnt++;
	cout<<cnt<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll n,m;
		cin>>n>>m;
		sang(n,m);	
	}	
}
