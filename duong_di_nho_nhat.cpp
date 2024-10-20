#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005][10005],dp[10005][10005];
const int Max=1e9;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) cin>>a[i][j];
}
void reset()
{
	dp[1][1]=a[1][1];
	for (int i=2;i<=m;i++) dp[1][i]=dp[1][i-1]+a[1][i];
	for (int i=2;i<=n;i++) dp[i][1]=dp[i-1][1]+a[i][1];
}
void process()
{
	reset();
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++) 
			dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+a[i][j];
	cout<<dp[n][m]<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		input();
		process();
	}
}
