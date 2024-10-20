#include <bits/stdc++.h>
using namespace std;
int n,a[205],csd,csc;
void nhap()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (a[i]==1) csd=i;
		if (a[i]==n) csc=i;
	}
	if (csc<csd) swap(csd,csc);
}
void xuly()
{
	if (n==0) 
	{
		cout<<"0";
		return;
	}
	cout<<max(n-csd,csc-1);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	xuly();
}
