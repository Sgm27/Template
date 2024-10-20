#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
#define maxbit 18
int n,k,par[maxn][maxbit + 2],h[maxn],root;
vector<int> meet[maxn >> 1],adj[maxn];
void dfs(int u)
{
    for (int v : adj[u])
        if (v!=par[u][0])
        {
            h[v]=h[u]+1;
            par[v][0]=u;
            FOR(i,1,maxbit)
                par[v][i]=par[par[v][i-1]][i-1];
            dfs(v);
        }
}
int LCA(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    FOD(i,maxbit,0)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
int get(vector<int> meet)
{
    int u = meet[0],max_dis = 0,new_u;
    FOR(i,1,meet.size() - 1)
    {
        int dis = h[u] + h[meet[i]] - 2 * h[LCA(u,meet[i])];
        if (dis > max_dis)
        {
            max_dis = dis;
            new_u = meet[i];
        }
    }
    u = new_u;
    FOR(i,0,meet.size() - 1)
    {
        int dis = h[u] + h[meet[i]] - 2 * h[LCA(u,meet[i])];
        if (dis > max_dis) max_dis = dis;
    }
    return max_dis;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n)
    {
        int id,x;
        cin>>id>>x;
        meet[id].push_back(i);
        if (!x)
        {
            root = i;
            continue;
        }
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(root);
    FOR(i,1,k) cout<<get(meet[i])<<"\n";
}
