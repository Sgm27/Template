#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,a[1000005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
ll tknp(ll a[],ll d,ll c,ll key)
{
	ll ans=-1;
	while (d<=c)
	{
		int mid=(d+c)/2;
		if (a[mid]>key)
		{
			ans=mid;
			c=mid-1;
		}
		else d=mid+1;
	}
	return ans;
}
void process()
{
	sort(a+1,a+n+1);
	ll res=0;
	for (int i=1;i<=n;i++)
	{
		ll x=tknp(a,i+1,n,k-a[i]);
		if (x!=-1) 
		{
			res+=n-x+1;
		}
	}	
	cout<<res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
