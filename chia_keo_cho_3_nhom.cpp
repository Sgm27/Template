#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 705
int n,dp[21][maxn][maxn],sum,a[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	FOR(i,1,n) cin>>a[i], sum+=a[i];
	int s=sum;
	sum=min(sum,1ll*(maxn-5));
	dp[0][0][0]=1;
	FOR(i,1,n)
		FOD(j,sum,0)
			FOD(k,sum,0)
			{
				if (dp[i-1][j][k]) dp[i][j][k]=1;
				if (k>=a[i] && dp[i-1][j][k-a[i]]) dp[i][j][k]=1;
				if (j>=a[i] && dp[i-1][j-a[i]][k]) dp[i][j][k]=1; 
			}
	int ans=INF;
	FOR(i,0,sum)
		FOR(j,0,sum)
			if (dp[n][i][j])
				ans=min(ans,max({i,j,s-i-j}));
	cout<<ans;
}
