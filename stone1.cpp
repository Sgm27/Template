#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 405
int n,f[maxn];
vector<int> adj[maxn];
void dfs(int u)
{
	if (adj[u].empty()) 
	{
		f[u] = 1;
		return;
	}
	priority_queue<int> pq;
	for (int v : adj[u])
	{
		dfs(v);
		pq.push(f[v]);
	}
	int stone = 0;
	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();
		f[u] = max(f[u], top + stone);
		stone++;
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
	int p,nChild; 
	while (cin>>p>>nChild)
	{
		FOR(i,1,nChild) 
		{
			int x; cin>>x;
			adj[p].push_back(x);
		}
	}
	dfs(1);
	cout<<f[1];
}
