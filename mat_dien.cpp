#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 1003
using ld = long double; 
const ld eps = 1e-9;
vector<pair<int,ld>> adj[maxn];
struct Point{
	int x,y;
} a[maxn];
int n,m;
ld maxW,f[maxn];
ld distance(Point a,Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void buildEdge()
{
	FOR(i,1,n-1)
		FOR(j,i+1,n)
		{
			ld dis = distance(a[i],a[j]);
			if (abs(dis - maxW) < eps) continue;
			if (dis < maxW)
			{
				adj[i].push_back({j,dis});
				adj[j].push_back({i,dis});
			}
		}
}
void dijkstra(int s)
{
	FOR(i,1,n) f[i] = 1e15;
	priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
	f[s] = 0.0;
	pq.push({f[s],s});
	while (!pq.empty())
	{
		ld du = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (abs(du - f[u]) > eps) continue;
		if (u == n) 
			return cout<<(int)(du*1000), void();
		for (pair<int,ld> it : adj[u])
		{
			int v = it.first;
			ld w = it.second;
			if (f[v] > f[u] + w)
			{
				f[v] = f[u] + w;
				pq.push({f[v],v});
			}
		}
	}
	cout<<"-1";
}	
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m>>maxW;
	FOR(i,1,n)
		cin>>a[i].x>>a[i].y;
	FOR(i,1,m)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back({v,0.0});
		adj[v].push_back({u,0.0});
	}
	buildEdge();
	dijkstra(1);
}
