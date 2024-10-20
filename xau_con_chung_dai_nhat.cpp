#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[10005][10005];
void input()
{
	cin>>s1>>s2;
}
void process()
{
	s1="#"+s1; int n=s1.length()-1;
	s2="#"+s2; int m=s2.length()-1;
	for (int i=1;i<=n;i++) dp[i][0]=0;
	for (int i=1;i<=m;i++) dp[0][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	cout<<dp[n][m]; 
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
