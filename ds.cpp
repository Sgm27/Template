#include <bits/stdc++.h>
using namespace std;
int n,a,b;
void nhap()
{
	cin>>n>>a>>b;
}
void xuly()
{
	int dem=0;
	for (int i=1;i<=n;i++)
		if (i%a==0 || i%b==0) dem++;
	cout<<dem;
}
int main()
{
	freopen("son.inp","r",stdin);
	nhap();
	xuly();
}
