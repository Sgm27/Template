#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[12][2002],m,n,stt=0;
void process()
{
	ll sum[2002];
	sum[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) dp[i][j]=0;
	for (int i=1;i<=m;i++) 
	{
		dp[1][i]=1;
		sum[i]=sum[i-1]+1;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=m;j++) dp[i][j]=sum[(int)(j/2)];
		for (int j=1;j<=m;j++) sum[j]=sum[j-1]+dp[i][j];
	}
	ll res=0;
	for (int i=1;i<=m;i++) res+=dp[n][i];
	cout<<"Data set "<<stt<<": "<<n<<" "<<m<<" "<<res<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	while (++stt<=tc)
	{
		cin>>n>>m;
		process();
	}
}

