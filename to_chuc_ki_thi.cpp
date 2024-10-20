#include <bits/stdc++.h>
using namespace std;
int n,m,k;
void input()
{
	cin>>n>>m>>k;
}
void process()
{
	int res;
	if (n/2>=m)
	{
		res=m;
		k-=(n-2*m);
	}
	else 
	{
		res=n/2;
		k-=(m-res+n%2);
	}
	while (k>0) 
	{
		res--;
		k-=3;
	}
	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
