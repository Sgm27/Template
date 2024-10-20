#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[200005],k;
map<int,int> mp;
int main()
{
	freopen("thu.inp","r",stdin);
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	ll res;
	sort(a+1,a+1+n);
	if (k==0)
	{
		res=1;
	}
	else
	{
		res=a[k];
	}
	int dem=0;
	for (int i=1;i<=n;i++)
		{
			if (a[i]<=res) dem++;
		}
	if (dem==k && a[k]>=1) cout<<a[k];
	else cout<<"-1";
}
