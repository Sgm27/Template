#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll n,Min=INT_MAX,Max=INT_MIN;
map<ll,ll> mp;
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		ll x; cin>>x;
		mp[x]++;
		Max=max(Max,x);
		Min=min(Min,x);
	}
}
void process()
{
	if (mp.size()>3) 
	{
		cout<<"NO";
		return;
	}
	if (mp.size()==1 || mp.size()==2) 
	{
		cout<<"YES";
		return;
	}
	if (mp.size()==3)
	{
		if ((Min+Max)%2==0 && mp.count((Min+Max)/2)) 
		{
			cout<<"YES";
			return;
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
