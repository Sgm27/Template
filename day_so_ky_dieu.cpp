#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll a[])
{
	for (int i=0;i<=9;i++) 
		if (!a[i]) return false;
	return true;
}
int main()
{
	freopen("thu.inp","r",stdin);
	ll n;
	while (cin>>n)
	{
		ll k=1,a[10]={0};
		while (1)
		{
			ll s=n*k;
			while (s)
			{
				a[s%10]++;
				s/=10;
			}
			if (check(a)) 
			{
				cout<<k<<endl;
				break;
			}
			else k++;
		}
	}
}
