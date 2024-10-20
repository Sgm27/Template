#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
void input()
{
	cin>>n;
}
bool check_special(ll k)
{
	for (ll i=2;i<=sqrt(k);i++) 
		if (k%(i*i)==0) return false;
	return true;
}
void process()
{
	vector<ll> v;
	for (ll i=1;i<=sqrt(n);i++)
		if (n%i==0) 
		{
			v.push_back(i);
			v.push_back(n/i);
		}
	sort(v.begin(),v.end(),greater<ll>());
	for (ll x : v)
		{
			if (check_special(x)) 
			{
				cout<<x;
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
