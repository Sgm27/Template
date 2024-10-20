#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105
int x[maxn],y[maxn],sm[maxn],pm[maxn],sl[maxn],pl[maxn],n,coin;
int cost[maxn],need[maxn];
bool f(int X)
{
	FOR(i,1,n) 
	{
		cost[i] = 0;
		need[i] = X*x[i] - y[i];
		need[i] = max(need[i],0ll);
	}
	int ans = 0;
	FOR(i,1,n)
	{
		cost[i] = need[i] / sm[i] * pm[i] + (need[i] % sm[i] ? pm[i] : 0);
		int first = 0;
		while (first * sm[i] <= need[i])
		{
			int second = (need[i] - first * sm[i]) / sl[i] + ((need[i] - first * sm[i]) % sl[i] ? 1 : 0);
			if (first * pm[i] + second * pl[i] < cost[i]) cost[i] = first * pm[i] + second * pl[i];
			first++;
		} 
		ans += cost[i];
	}
	if (ans <= coin) return true;
	return false;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>coin;
	FOR(i,1,n)
		cin>>x[i]>>y[i]>>sm[i]>>pm[i]>>sl[i]>>pl[i];
	int l = 0, r = 1e5;
	while (r-l > 1)
	{
		int m = l+r >> 1;
		if (f(m)) l = m;
		else r = m;
	}
	cout<<l;
}
