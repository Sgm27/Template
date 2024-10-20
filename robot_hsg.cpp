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
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		vector<pii> points(n+2);
		points[0].first = 0;
		FOR(i,1,n)
			cin>>points[i].first>>points[i].second;
		cin>>points[n+1].first>>points[0].second;
		FOR(i,1,n)
			points[i].first = points[n+1].first - points[i].first;
		priority_queue<int> pq;
		int cur = 0, ans = 0;
		FOR(i,0,n+1)
		{
			if (i == 0)
			{
				cur += points[i].second;
				continue;
			}
			int diff = points[i].first - points[i-1].first;
			while (!pq.empty() && cur < diff)
			{
				cur += pq.top();
				pq.pop();
				ans++;
			}
			if (pq.empty() && cur < diff)
			{
				ans = -1;
				break;
			}
			cur -= diff;
			pq.push(points[i].second);
		}
		cout<<ans<<"\n";
	}
}
