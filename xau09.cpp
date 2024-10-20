#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> res;
ll n,x[100000],a[501];
void in()
{
	string tmp;
	for (int i=1;i<=15;i++)
	if (x[i]==0) tmp+='0';
	else tmp+='9';
	res.push_back(stoll(tmp));
}
void thu(int i)
{
	for (int j=0;j<=1;j++)
	{
		x[i]=j;
		if (i==15) in();
		else thu(i+1);
	}
}
void xuly()
{
	for (int i=1;i<=500;i++)
		for (ll x : res)
			if (x%i==0 && x!=0) 
		{
			a[i]=x; 
			break;
		}
}
int main()
{
	freopen("son.inp","r",stdin);
	thu(1);
	xuly();
	int tc; cin>>tc;
	while (tc--)
	{
		int k;
		cin>>k;
		cout<<a[k]<<" ";
	}
}
