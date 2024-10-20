#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool kt(ll x)
{
	return (x>=-1e9 && x<=1e9);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		ll n,a[50];
		vector<ll> res;
		cin>>n;
		for (int i=1;i<=50;i++) a[i]=1e17;
		for (int i=1;i<=n*(n-1)/2;i++) cin>>a[i];
		ll chot;
		if ((a[2]-a[1]+a[n])%2==0) chot=a[2]-(a[2]-a[1]+a[n])/2;
		else 
		{
			cout<<"-1\n";
			continue;
		}	
		bool check=true;
		if (kt(chot)) res.push_back(chot);
		else check=false;
		for (int i=1;i<=n-1;i++) 
			if (kt(a[i]-chot)) res.push_back(a[i]-chot); else check=false;
		if (!check) 
		{
			cout<<"-1\n";
			continue;
		}
		cout<<"1 ";
		sort(res.begin(),res.end());
		for (int k : res) cout<<k<<" ";
		cout<<endl;
	}
}
