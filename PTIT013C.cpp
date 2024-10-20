#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll xa,ya,xb,yb;
ll kc(ll xa,ll ya,ll xb,ll yb)
{
	return (ll)sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
void process()
{
	if (ya*yb<=0) 
	{
		cout<<kc(xa,ya,xb,yb);
		cout<<endl;
	}
	else 
	{
		cout<<kc(xa,-ya,xb,yb);
		cout<<endl;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>xa>>ya>>xb>>yb;
		process();
	}
}
