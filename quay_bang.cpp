#include <bits/stdc++.h>
using namespace std;
double a1,a2,a3,a4;
int main()
{	
	//freopen("thu.inp","r",stdin);
	cin>>a1>>a3>>a2>>a4;
	int res=0;
	double Max=(double)(abs(a1/a2-a3/a4));
	if ((double)(abs(a2/a4-a1/a3))>Max)
	{
		Max=(double)(abs(a2/a4-a1/a3));
		res=1;
	}
	if ((double)(abs(a4/a3-a2/a1))>Max)
	{
		Max=(double)(abs(a4/a3-a2/a1));
		res=2;
	}
	if ((double)(abs(a3/a1-a4/a2))>Max)
	{
		Max=(double)(abs(a3/a1-a4/a2));
		res=3;
	}
	cout<<res;
}
