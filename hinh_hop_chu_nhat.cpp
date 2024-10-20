#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>x>>y>>z;
	int a,b,c;
	c=sqrt(z*y/x);
	a=y/c;
	b=x/a;
	cout<<(a+b+c)*4;
}
