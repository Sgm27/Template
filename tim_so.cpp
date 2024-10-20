#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
set<ll> se;
void input()
{
	cin>>n;
}
void process(ll n)
{
	for (int i=1;i*(i+1)/2<=n;i++)
	{
		ll tmp=i*(i+1)/2;
		se.insert(tmp);
		if (se.count(n-tmp)) 
		{
			cout<<"YES";
			return;	
		} 
	}
	cout<<"NO";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process(n);
}
