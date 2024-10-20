#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void process(ll n)
{
	ll i=2;
	while (n!=1)
	{
		while (n%i==0)
		{
			cout<<i<<" ";
			n/=i;
		}
		i++;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	for (int i=1;i<=tc;i++)
	{
		ll n;
		cin>>n;
		process(n);
		cout<<endl;
	}
}
