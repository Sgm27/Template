#include <bits/stdc++.h>
using namespace std;
int dp[35][35];
int process(string s1,string s2)
{
	int res=-1;
	int n=s1.length(),m=s2.length();
	s1="#"+s1;
	s2="#"+s2;
	for (int i=1;i<=n;i++) dp[i][0]=0;
	for (int i=1;i<=m;i++) dp[0][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			res=max(res,dp[i][j]);
		}
	return res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc,n;
	cin>>tc;
	while (tc--)
	{
		int result=-1;
		string s[105];
		cin>>n;
		for (int i=1;i<=n;i++) cin>>s[i];
		for (int i=1;i<=n-1;i++)
			for (int j=i+1;j<=n;j++)
				result=max(result,process(s[i],s[j]));
		cout<<result<<endl;
	}
}
