#include <bits/stdc++.h>
using namespace std;
int n,s,a[105];
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	int res=-1;
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			for (int k=j+1;k<=n;k++)
				if (a[i]+a[j]+a[k]<=s && a[i]+a[j]+a[k]>res) res=a[i]+a[j]+a[k];
	cout<<res; 
}
