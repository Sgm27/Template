#include <bits/stdc++.h>
using namespace std;
int n,m,v[105],w[105],dp[105][10005];
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
}
void process()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (j>=w[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j]=dp[i-1][j];
	cout<<dp[n][m];
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
