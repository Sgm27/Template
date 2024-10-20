#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool cp(ll k)
{
	ll tmp=sqrt(k);
	return tmp*tmp==k;
}
bool check(ll k)
{
	ll sum=0;
	for (int i=1;i<=sqrt(k);i++) 
		if (k%i==0)
		{
			sum+=i;
			sum+=k/i;
		}
	if (cp(k)) sum-=sqrt(k);
	ll sum2=0;
	for (int i=1;i<=sqrt(sum);i++)
		if (sum%i==0)
		{
			sum2+=i;
			sum2+=sum/i;
		}
	if (cp(sum)) sum2-=sqrt(sum);
	if (sum2%2) return false;
	return k==sum2/2;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll tmp;
		cin>>tmp;
		if (check(tmp)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
