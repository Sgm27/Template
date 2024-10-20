#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main()
{
	ll n;
	cin>>n;
	ll sum=0;
	for (int i=1;i<=n;i++) 
	{
		ll x;
		cin>>x;
		sum+=x;
	}
	cout<<sum;
}
