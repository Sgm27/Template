#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005];
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		if (a[i]+a[j]==m) cnt++;
	cout<<cnt;
}
