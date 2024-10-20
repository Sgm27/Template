#include <bits/stdc++.h>
using namespace std;
int n,k,a[100];
void nhap()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void xuly()
{
	int csd,csc;
	int max=-1;
	int sum=0,res;
	for (int i=1;i<=k;i++) sum+=a[i];
	res=sum;
	csd=1; csc=k;
	for (int i=2;i<=n-k+1;i++)
	{
		sum-=a[i-1];
		sum+=a[i+k-1];
		if (sum>res)
		{
			res=sum;
			csd=i;
			csc=i+k-1;
		}
	}
	cout<<res<<endl;
	cout<<csd<<" "<<csc;
}
int main()
{
	freopen("son.inp","r",stdin);
	nhap();
	xuly();
}
