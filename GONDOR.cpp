#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 105
using ld = long double;
const ld eps = 1e-9;
vector<pair<int,ld>> adj[maxn];
ld f[maxn];
int n,S[maxn],mark[maxn];
pii a[maxn];
ld distance(pii a,pii b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
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
        mark[u] = 1;
        int cnt = 1;
		for (pair<int,ld> it : adj[u])
		{
			int v = it.first;
			ld w = it.second;
            if (mark[v]) continue;
			if (f[v] > f[u] + w)
			{
				f[v] = f[u] + w;
				pq.push({f[v],v});
			}
            cnt++;
            if (cnt > S[u]) break;
		}
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
    FOR(i,1,n)
    {
        mark[i] = 0;
        cin>>a[i].first>>a[i].second;
        cin>>S[i];
        FOR(j,1,n-1)
        {
            int v; cin>>v;
            adj[i].push_back({v,0.0});
        }
    }
    FOR(i,1,n)
        for (int j = 0;j < adj[i].size();j++) adj[i][j].second = distance(a[i],a[adj[i][j].first]);
    dijkstra(1);
    FOR(i,1,n) cout<<fixed<<setprecision(6)<<f[i]<<"\n";
}
