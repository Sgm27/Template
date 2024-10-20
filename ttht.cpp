#include <bits/stdc++.h>
using namespace std;
int n,k,a[100],s[100];
void nhap()
{
	s[0]=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
}
int main()
{
	freopen("son.inp","r",stdin);
	nhap(); int csd,csc;
	int res=0;
	for (int i=k;i<=n;i++)
	{
		if (s[i]-s[i-k]>res)
		{
			res=s[i]-s[i-k];
			csd=i-k+1;
			csc=i;
		}
	}
	cout<<res<<endl;
	cout<<csd<<" "<<csc;
}
