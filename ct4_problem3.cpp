#include <bits/stdc++.h>
using namespace std;
using ll=long long;
set<ll> se;
ll n,a[205][205];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
}
bool nto(ll k)
{
	if (k==2 || k==3) return true;
	if (k<2 || k%2==0 || k%3==0) return false;
	ll i=5;
	while (i<sqrt(k))
	{
		if (k%i==0 || k%(i+2)==0) return false;
		else i+=6;
	}
	return true;
}
void process()
{
	int cnt=0;
	int j=n;
	for (int i=1;i<=n;i++) 
	{
		if (nto(a[i][i]) && !se.count(a[i][i])) 
		{
			cnt++;
			se.insert(a[i][i]);
		}
		if (nto(a[i][j]) && !se.count(a[i][j]))
		{
			cnt++;
			se.insert(a[i][j]);
		}
		j--;
	}
	cout<<cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
