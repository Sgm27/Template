#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
#define bit(n,i) ((n>>i)&1)
int n,m,k,c[maxn][maxn],s[20],dp[1<<15][16];
void input()
{
	cin>>n>>m>>k;
	for (int i=0;i<k;i++)
	{
		cin>>s[i];
		s[i]-=1;
	}
	for (int i=0;i<m;i++) 
	{
		int u,v,w;
		cin>>u>>v>>w;
		c[u-1][v-1]=w;
	}
}
void process()
{
	for (int mask=1;mask<(1<<k);mask++)
	{
		for (int i=0;i<k;i++)
			if (bit(mask,i) && bit(mask,0))
			{
				if(__builtin_popcount(mask)==1) dp[mask][i]=c[0][s[i]];
				else
				{
					int pre_mask=mask-(1<<i);
					for (int j=0;j<k;j++)
						if (bit(pre_mask,j) && c[s[j]][s[i]]) 
							dp[mask][i]=min(dp[mask][i],dp[pre_mask][j]+c[s[j]][s[i]]);
				}
				cout<<mask<<" "<<i<<" "<<dp[mask][i]<<"\n";
			}
	}
	int ans=1e9;
	for (int i=0;i<k;i++)
		ans=min(ans,dp[(1<<k)-1][i]+c[s[i]][0]);
	if (ans && ans!=(1e9)) cout<<ans;
	else cout<<"-1";
}
int main()
{
	freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	process();
}

