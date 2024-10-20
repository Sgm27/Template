#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,tt=0;
vector<ll> v;
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
void init()
{
	for (int i=1;i<=100000;i++)
	{
		ll tmp=(i*(i+1))/2;
		if (cp(tmp+1)) v.push_back(tmp+1);
	}
}
void process()
{
	cout<<"Case "<<tt<<": ";
	ll cnt=0;
	for (ll x : v)
	{	
		if (x>=m) break;
		if (x>n && x<m) cnt++;
	}
	cout<<cnt<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	init();
	while (cin>>n>>m)
	{
		tt++;
		if (n==0 && m==0) return 0;
		process();
	}
}
