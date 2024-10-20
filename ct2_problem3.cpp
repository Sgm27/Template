#include <bits/stdc++.h>
using namespace std;
int n,a[105][105],dp[105][105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
}
void init()
{
	for (int i=1;i<=n;i++) 
	{
		dp[0][i]=INT_MIN;
		dp[n+1][i]=INT_MIN;
		dp[i][0]=0;
	}
}
void process()
{
	for (int j=1;j<=n;j++)
		for (int i=1;i<=n;i++)
		{
			dp[i][j]=a[i][j]+max(dp[i-1][j-1],max(dp[i][j-1],dp[i+1][j-1]));
		}
	int Max=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		Max=max(Max,dp[i][n]);
	}
	cout<<Max;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	init();
	process();
}
