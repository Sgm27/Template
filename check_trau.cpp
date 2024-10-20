#ifdef DS
	#include "debug.h"
#else 
	#include<bits/stdc++.h>
	#define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	freopen("check.ans","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	while (tc--)
	{
		int n,m; cin>>n>>m;	
		vector<vi> g(n+1);
		FOR(i,1,m)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		vi mark(n+1);
		function<bool(int)> dfs = [&](int u)
		{
			mark[u] = 1;
			bool res = false;
			for (int v : g[u])
				if (!mark[v])
				{
					mark[v] = 1;
					res |= dfs(v);
				}
				else
				if (mark[v] == 1) return true;
			mark[u] = 2;
			return res;
		};
		bool ans = false;
		FOR(i,1,n)
			if (!mark[i]) ans |= dfs(i);
		cout<<(ans ? "YES\n" : "NO\n");
	}
}