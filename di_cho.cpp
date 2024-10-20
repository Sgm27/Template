#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll y,k,n;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>y>>k>>n;
	ll cnt=n/k;
	bool check = false;
	for (int i=1;i<=cnt;i++)
		if (k*i-y>=1) 
		{
			cout<<k*i-y<<" ";
			check = true;
		}
	if (!check) cout<<"-1";
}
