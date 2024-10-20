#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b;
void input()
{
	cin>>a>>b;
}
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return true;
	return false;
}
void process()
{
	if (a==b) 
	{
		cout<<"infinity";
		return;
	}
	if (a<b) 
	{
		cout<<0;
		return;
	}
	ll tmp=a-b;
	ll cnt=0;
	for (ll i=1;i<sqrt(tmp);i++)
		if (tmp%i==0)
		{
			if (i>b) cnt++;
			if (tmp/i>b) cnt++;
		}
	if (cp(tmp) && sqrt(tmp)>b) cnt++;
	cout<<cnt; 
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
