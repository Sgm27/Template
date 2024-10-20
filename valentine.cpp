#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],den=0,trang=0;
int main()
{
	memset(a,2,sizeof(a));
//	freopen("thu.inp","r",stdin);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1) den++;
		if (a[i]==-1) trang++;
	}
	int Max=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		int dt=den,tt=trang;
		int j=i;
		while (j<=n)
		{
			if (a[j]==1) dt--;
			if (a[j]==-1) tt--;
			j+=k;
		}
		j=i-k;
		while (j>=1)
		{
			if (a[j]==1) dt--;
			if (a[j]==-1) tt--;
			j-=k;
		}
		//cout<<dt<<" "<<tt<<endl;
		Max=max(Max,abs(dt-tt));
	}
	cout<<Max;
}
