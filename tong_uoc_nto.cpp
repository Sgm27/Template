#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll prime[10000001],kq=0;
void sang()
{
	for (int i=1;i<=10000000;i++)
	{
		prime[i]=i;
	}
	for (int i=2;i<=sqrt(10000000);i++)
		if (prime[i])
		{
			for (int j=i*i;j<=10000000;j+=i)
				if (prime[j]==j) prime[j]=i;
		}
}
ll pt(ll n)
{
	ll res=0;
	while (n!=1)
	{
		res+=prime[n];
		n/=prime[n];
	}
	return res;
}
int main()
{
	sang();
	freopen("thu.inp","r",stdin);
	ll tc; cin>>tc;
	while (tc--)
	{
		ll n; cin>>n;
		kq+=pt(n);
	}
	cout<<kq;
}
