#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18,BLOCK_SZ = 502;
#define maxn 100005
int n,m,k,timer,res,ans[maxn];
int color[maxn],in[maxn],out[maxn],inColor[maxn],cnt[maxn];
vector<int> adj[maxn];
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
} Q[maxn];
void dfs(int u)
{
	in[u] = ++timer;
	inColor[timer] = color[u];
	for (int v : adj[u]) 
		dfs(v);
	out[u] = timer;
}
void add(int x)
{
	cnt[x]++;
	if (cnt[x] == k + 1) res--;
	if (cnt[x] == 1) res++;
}
void rem(int x)
{
	cnt[x]--;
	if (cnt[x] == k) res++;
	if (cnt[x] == 0) res--;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m>>k;
	FOR(i,2,n)
	{
		int p; cin>>p;
		adj[p].push_back(i);
	}
	FOR(i,1,n) cin>>color[i];
	dfs(1);
	int q; cin>>q;
	FOR(i,1,q)
	{
		int x; cin>>x;
		Q[i]={in[x],out[x],i};
	}
	sort(Q+1,Q+1+q);
	int curL=1, curR=0;
    FOR(i,1,q)
    {
        int left=Q[i].l;
        int right=Q[i].r;
        while (curR < right) add(inColor[++curR]);
        while (curR > right) rem(inColor[curR--]);
        while (curL < left) rem(inColor[curL++]);
        while (curL > left) add(inColor[--curL]);
        ans[Q[i].id] = res;
    }
    FOR(i,1,q) cout<<ans[i]<<"\n";
}
