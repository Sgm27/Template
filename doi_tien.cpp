#include <bits/stdc++.h>
using namespace std;
int n,m,l[10005],a[105];
const int Max=1e9;
void process()
{
	for (int i=0;i<=m;i++) l[i]=Max;
	l[0]=0;
	for (int j=1;j<=m;j++)
		for (int i=1;i<=n;i++)
			if (j>=a[i]) l[j]=min(l[j],l[j-a[i]]+1);
	if (l[m]!=Max) cout<<l[m];
	else cout<<"-1";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	process();
}
