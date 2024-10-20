#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],sum,dp[10005];
void input()
{
	cin>>n>>k;
	sum=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}
}
void process()
{
	dp[0]=1;
	for (int i=1;i<=sum;i++) dp[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=sum;j>=0;j--)
			if (dp[j] && !dp[j+a[i]])
			{
				dp[j+a[i]]=1;
				if (j+a[i]==k) 
				{
					cout<<"YES\n";
					return;
				}
			}
	cout<<"NO\n";
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

