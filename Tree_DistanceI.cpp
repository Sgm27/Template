// maximum distance of i th node to other if max of dist(i,a), dist(i,b)
// with a and b are two end point of daimeter of tree 
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
int n,a[maxn],d[3][maxn];
vector<int> adj[maxn];
void dfs(int u,int par,int type)
{
    for (int v : adj[u])
        if (v != par)
        {
            d[type][v] = d[type][u] + 1;
            dfs(v,u,type);
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
    FOR(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0);
    int first_daim,max_dis = -1;
    FOR(i,1,n)
        if (d[0][i] > max_dis) 
        {
            max_dis = d[0][i];
            first_daim = i;
        }
    dfs(first_daim,-1,1);
    int second_daim;
    max_dis = -1;
    FOR(i,1,n)
        if (d[1][i] > max_dis)
        {
            max_dis = d[1][i];
            second_daim = i;
        }
    dfs(second_daim,-1,2);
    FOR(i,1,n) cout<<max(d[1][i], d[2][i])<<" ";
}
