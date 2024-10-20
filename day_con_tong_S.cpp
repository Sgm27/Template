#include <bits/stdc++.h>
using namespace std;
int n,s,a[205],dp[8000005];
void input()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	dp[0]=1;
	for (int i=1;i<=n;i++)
		for (int t=s;t>=a[i];t--)
			if (!dp[t] && dp[t-a[i]])
			{
				dp[t]=1;
				if (dp[s])
				{
					cout<<"YES";
					return;
				}
			}
	cout<<"NO";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
