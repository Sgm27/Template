#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18, BLOCK_SZ = 1024;
#define maxn 200005
int n,a[maxn],in[maxn],out[maxn],timer,color[maxn];
vector<int> adj[maxn];
int BLOCK_SZ;
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
};
vector<query> queries;
void euler(int u,int par)
{
	in[u] = ++timer;
	color[timer] = a[u];
	for (int v : adj[u])
	{
		if (v == par) continue;
		euler(v,u);
	}
	out[u] = timer;
}
int res,ans[maxn],cnt[maxn];
inline void add(int x)
{
	cnt[x]++;
	if (cnt[x] == 1) res++;
}
inline void rem(int x)
{
	cnt[x]--;
	if (cnt[x] == 0) res--;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	BLOCK_SZ = sqrt(n);
	vector<int> compress;
	FOR(i,1,n) cin>>a[i], compress.push_back(a[i]);
	sort(ALL(compress));
	compress.resize(unique(ALL(compress)) - compress.begin());
	FOR(i,1,n) a[i] = lower_bound(ALL(compress),a[i]) - compress.begin();
	FOR(i,1,n-1)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	euler(1,-1);
	FOR(i,1,n) 
		queries.push_back({in[i],out[i],i});
	sort(ALL(queries));
	int curL=1, curR=0;
    for (auto it : queries)
    {
        int left = it.l;
        int right = it.r;
        while (curR < right) add(color[++curR]);
        while (curR > right) rem(color[curR--]);
        while (curL < left) rem(color[curL++]);
        while (curL > left) add(color[--curL]);
        ans[it.id] = res;
    }
	FOR(i,1,n) cout<<ans[i]<<" ";
}
