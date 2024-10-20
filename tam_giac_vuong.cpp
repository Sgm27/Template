#include <bits/stdc++.h>
using namespace std;
bool check(int a,int b,int c)
{
	if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) return true;
	return false;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int a,b,c;
	while (1)
	{
		cin>>a>>b>>c;
		if (a==0 && b==0 && c==0) return 0;
		if (check(a,b,c)) cout<<"right\n";
		else cout<<"wrong\n";
	}
}
