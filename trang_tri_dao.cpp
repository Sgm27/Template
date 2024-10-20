#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>a>>b>>c;
	if (b>=c) b=c-1;
	if (a>=b) a=b-1;
	cout<<3*a+3;
}
