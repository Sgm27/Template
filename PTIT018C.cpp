#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll bigmod(string s,ll m)
{
	ll res=0;
	for (int i=0;i<s.length();i++)
		res=(res*10+(s[i]-'0'))%m;
	return res;
}
ll process(ll a,ll b,ll m)
{
	ll res=a;
	for (int i=2;i<=b;i++)
		{
			res*=a;
			res%=m;
		}
	return res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string a;
		ll b,m;
		cin>>a>>b>>m;
		cout<<process(bigmod(a,m),b,m)<<endl;
	}
}
