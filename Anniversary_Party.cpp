#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 6005
int n,f[2][maxn],isChild[maxn];
vector<int> adj[maxn];
void dfs(int u)
{
	for (int v : adj[u])
	{
		dfs(v);
		f[0][u] += max({f[1][v],f[0][v],0LL});
		f[1][u] += max(f[0][v],0LL);
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
	FOR(i,1,n) cin>>f[1][i];
	int u,v;
	while (cin>>v>>u)
	{
		if (!u && !v) break;
		isChild[v] = 1;
		adj[u].push_back(v);
	}
	int root;
	FOR(i,1,n)
		if (!isChild[i]) 
		{
			root = i;
			break;
		} 
	dfs(root);
	cout<<max({0LL,f[0][root],f[1][root]});
}
