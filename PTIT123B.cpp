#include <bits/stdc++.h>
using namespace std;
int n,a[25],tt=0;
void process()
{
	cout<<"Case "<<tt<<": ";
	a[n+1]=a[1];
	int cnt=0;
	bool check=true;
		for (int i=1;i<=n-1;i++)
			if (a[i]!=a[i+1]) check=false;
		if (check) 
		{
			cout<<cnt<<" iterations\n";
			return;
		}
	while (cnt<=1000)
	{
		cnt++;
		a[n+1]=a[1];
		for (int i=1;i<=n;i++) a[i]=abs(a[i+1]-a[i]);
		check=true;
		for (int i=1;i<=n-1;i++)
			if (a[i]!=a[i+1]) 
			{
				check=false;
				continue;
			}
		if (check) 
		{
			cout<<cnt<<" iterations\n";
			return;
		}
	}
	cout<<"not attained\n";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		tt++;
		if (n==0) return 0;
		for (int i=1;i<=n;i++) cin>>a[i];
		process();
	}
}
