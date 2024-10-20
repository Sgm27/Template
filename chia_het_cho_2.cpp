#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
ll process(ll n)
{
	ll cnt=0;	
	for (int i=1;i<=sqrt(n);i++)
	{
		if (n%i==0 && (i%2==0)) cnt++;
		if (n%i==0 && (n/i)%2==0) cnt++; 
	}
	if (cp(n) && ((ll)sqrt(n)%2==0)) cnt--;
	return cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll n; cin>>n;
		cout<<process(n)<<endl;
	}
}
