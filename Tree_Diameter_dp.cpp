#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,f[2][maxn];
vector<int> adj[maxn];
void dfs(int u,int par)
{
	for (int v : adj[u])
		if (v != par)
		{
			dfs(v,u);
			if (f[0][u] <= f[0][v] + 1)
			{
				f[1][u] = f[0][u];
				f[0][u] = f[0][v] + 1;
			}
			else
			if (f[1][u] < f[0][v] + 1)
				f[1][u] = f[0][v] + 1;
		}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	FOR(i,1,n-1)
	{
		int u,v; 
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	int ans = -1;
	FOR(i,1,n) ans = max(ans,f[0][i] + f[1][i]);
	cout<<ans;
}
