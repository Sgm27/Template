#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[1005][25];
void process()
{
	int res,Max=INT_MIN;
	for (int i=1;i<=m;i++)
	{
		ll tmp=1;
		for (int j=1;j<=n;j++) tmp*=a[j][i];
		if (tmp>=Max)
		{
			Max=tmp;
			res=i;	
		} 
	}
	cout<<res<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	while (1)
	{
		cin>>m>>n;
		if (n==0 && m==0) return 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) cin>>a[i][j];
		process();
	}
}
