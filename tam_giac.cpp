#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,x,y,z;
void nhap()
{
	cin>>a>>b>>x>>y>>z;
}
void process()
{
	if (x*x+y*y!=z*z && x*x+z*z!=y*y && y*y+z*z!=x*x) 
	{
		cout<<"NO";
		return;
	}
	ll Min=min(a,b);
	ll Max=max(a,b);
	ll tmp1=min(x,min(y,z));
	ll tmp2=max(x,max(y,z));
	ll tmp3=sqrt(tmp2*tmp2-tmp1*tmp1);
	if (tmp1<=Min && tmp3<=Max) 
	{
		cout<<"YES";
		return;
	}
	cout<<"NO";
}
int main()
{
	freopen("thu.inp","r",stdin);
	nhap();
	process();
}
