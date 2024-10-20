#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b,c,x,y,z;
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>x>>y>>z;
		c=sqrt(y*z/x);
		b=z/c;
		a=x/b;
		cout<<(a+b+c)*4<<endl;
	}
}
