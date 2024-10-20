#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18, BLOCK_SZ = 512;
#define maxn 100005
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
};
int n,a[maxn],tin[maxn],tout[maxn],timer,res;
int ans[maxn],cnt[maxn],sum[maxn],max_fre,have[maxn],color[maxn];
vector<int> adj[maxn];
vector<query> queries;
void euler(int u,int par = -1)
{
    tin[u] = ++timer;
    color[timer] = a[u];
    for (int v : adj[u])
        if (v != par) euler(v,u);
    tout[u] = timer;
}
inline void add(int x)
{
    sum[cnt[color[x]]] -= color[x];
    have[cnt[color[x]]]--;
    cnt[color[x]]++;
    if (have[cnt[color[x]]] == 0) max_fre = max(max_fre, cnt[color[x]]);
    have[cnt[color[x]]]++;
    sum[cnt[color[x]]] += color[x];
}
inline void rem(int x)
{
    sum[cnt[color[x]]] -= color[x];
    have[cnt[color[x]]]--;
    if (have[max_fre] == 0) max_fre--;
    cnt[color[x]]--;
    have[cnt[color[x]]]++;
    sum[cnt[color[x]]] += color[x];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    euler(1);
    FOR(i,1,n) queries.push_back({tin[i],tout[i],i});
    sort(queries.begin(),queries.end());
    int curL=1, curR=0;
    for (auto it : queries)
    {
        int left=it.l;
        int right=it.r;
        while (curR < right) add(++curR);
        while (curR > right) rem(curR--);
        while (curL < left) rem(curL++);
        while (curL > left) add(--curL);
        ans[it.id] = sum[max_fre];
    }
    FOR(i,1,n) cout<<ans[i]<<" ";
}
