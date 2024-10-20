#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b;
vector<ll> v;
void process()
{
	ll tmp=__gcd(a,b);
	for (int i=1;i<=sqrt(tmp);i++)
		if (tmp%i==0)
		{
			v.push_back(i);
			if (i!=tmp/i) v.push_back(tmp/i);
		}
	sort(v.begin(),v.end());
	int q;
	cin>>q;
	while (q--)
	{
		ll x,y;
		cin>>x>>y;
		int idx=upper_bound(v.begin(),v.end(),y)-v.begin();
		idx--;
		while (v[idx]>y) idx--;
		if (v[idx]>=x) cout<<v[idx]<<endl;
		else cout<<"-1\n";
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>a>>b;
	process();
}
