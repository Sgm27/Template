#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[100005],Min=1e9,tmin=1e9;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		Min=min(Min,a[i]);
	}
}
ll check(ll k)
{
	ll res=0;
	for (int i=1;i<=n;i++) res+=k/a[i];
	return res;
}
ll process()
{
	ll l=1,r=Min*m,ans;
	while (l<=r)
	{
		ll mid=(l+r)/2;
	//	cout<<mid<<" "<<check(mid)<<" "<<m<<endl;
		if (check(mid)<m)
		{
			l=mid+1;
		}
		else 
		{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	cout<<process();
}
