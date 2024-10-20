#include<bits/stdc++.h>
using namespace std;
int n,x,y,res;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>n; res=-1;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		res=max(res,x+y);
	}
	cout<<res;
}
