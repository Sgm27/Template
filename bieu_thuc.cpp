#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,a[100005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	sort(a+2,a+1+n,greater<ll>());
	ll sum=a[1];
	for (int i=2;i<=n;i++)
	{
		if (k) 
		{
			sum+=a[i];
			k--;
		}
		else sum-=a[i];
	}
	cout<<sum;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	process();
}
