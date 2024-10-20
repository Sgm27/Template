#include <bits/stdc++.h>
using namespace std;
int d[5005],n;
int main()
{
//	freopen("thu.inp","r",stdin);
	memset(d,0,sizeof(d));
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		int tmp;
		cin>>tmp;
		d[tmp]=1;
	}
	int res=0;
	for (int i=1;i<=n;i++) 
	{
		if (!d[i]) res++;
	}
	cout<<res;
}
