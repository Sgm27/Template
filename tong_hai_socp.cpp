#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll d[50000]={0};
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return true;
	return false;
}
ll process(ll n)
{
	if (n==0) return 1;
	ll cnt=0;
	for (ll i=0;i<=sqrt(n);i++)
		if (cp(n-i*i)) cnt++;	
	return cnt/2;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll n; cin>>n;
		cout<<process(n)<<endl;
	}
}
