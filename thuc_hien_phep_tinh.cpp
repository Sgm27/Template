#include <bits/stdc++.h>
using namespace std;
int a,b,c;
void process()
{
	if (a==b+c) 
	{
		cout<<a<<"="<<b<<"+"<<c;
		return;
	}
	if (a==b-c) 
	{
		cout<<a<<"="<<b<<"-"<<c;
		return;
	}
	if (a==b*c) 
	{
		cout<<a<<"="<<b<<"*"<<c;
		return;
	}
	if (a==b/c) 
	{
		cout<<a<<"="<<b<<"/"<<c;
		return;
	}
	if (a+b==c) 
	{
		cout<<a<<"+"<<b<<"="<<c;
		return;
	}
	if (a-b==c) 
	{
		cout<<a<<"-"<<b<<"="<<c;
		return;
	}
	if (a*b==c) 
	{
		cout<<a<<"*"<<b<<"="<<c;
		return;
	}
	if (a/b==c) 
	{
		cout<<a<<"/"<<b<<"="<<c;
		return;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>a>>b>>c;
	process();
}
