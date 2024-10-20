#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
void process()
{
	int Max=INT_MIN;
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			for (int k=j+1;k<=n;k++) 
				if (a[i]+a[j]+a[k]<=m) Max=max(Max,a[i]+a[j]+a[k]);
	cout<<Max<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		process();
	}
}
