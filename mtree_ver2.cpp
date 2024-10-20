#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,f[maxn],ans;
vector<pii> adj[maxn];
int Pow(int a, int n)
{
	if (!n) return 1;
	if (n==1) return a;
	int tmp=Pow(a,n/2)%MOD;
	tmp=tmp*tmp%MOD;
	if (n%2) tmp=tmp*a%MOD;
	return tmp;
}
int inv2 = Pow(2,MOD-2);
void dfs(int u,int par)
{
	int bp = 0;
	for (auto it : adj[u])
	{
		int v = it.first;
		int w = it.second;
		if (v == par) continue;
		dfs(v,u);
		int cost = (w * f[v] + w) %MOD;
		f[u] = (f[u] + cost) %MOD;
		bp = (bp + cost * cost) %MOD;
	}
	int cost_in_u = ((f[u] * f[u])%MOD - bp + MOD*MOD)%MOD;
	cost_in_u = (cost_in_u * inv2)%MOD; 
	ans = (ans + f[u] + cost_in_u) %MOD;
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
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs(1,-1);
	cout<<ans;
}
