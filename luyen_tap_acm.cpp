#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int n,res=0;
	cin>>n;
	while (n--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (x+y+z>=2) res++;
	}
	cout<<res;
}
