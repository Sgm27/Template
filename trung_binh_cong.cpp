#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[100005];
ll cnt=0,dem=0,res=-1;
ll Max=INT_MIN;
int main()
{
	freopen("thu.inp","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	for (int i=1;i<=n;i++)
		{
			if (a[i]==Max) cnt++;
		}
	if (cnt==1) cout<<1;
	else 
	{
		ll i=1;
		while (i<=n)
		{
			bool ok=true;
			while (a[i]==Max)
			{
				dem++;
				i++;
				ok=false;
			}
			res=max(res,dem);
			dem=0;
			if (ok) i++;
		}
		cout<<res;
	}
	return 0;
}
