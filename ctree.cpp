#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 10005
#define max_color 10
int n,f[max_color+1][maxn],color[maxn];
vector<int> adj[maxn];
void dfs(int u,int par)
{
    if (par != -1 && adj[u].size() == 1)
    {
        FOR(i,1,max_color) f[i][u] = i;
        return;
    }
    for (int v : adj[u])
        if (v != par)
        {
            dfs(v,u);
            FOR(i,1,max_color)
            {
                int Min = INF;
                FOR(j,1,max_color)
                    if (j != i) Min = min(Min,f[j][v]);
                f[i][u] += Min;
            }
        }
    FOR(i,1,max_color) f[i][u] += i;
}
void Tracing(int u,int cl)
{
    for (int v : adj[u])
        if (!color[v]) 
        {
            int min_color, Min = INF;
            FOR(i,1,max_color)
                if (i != cl && Min > f[i][v]) 
                {
                    Min = f[i][v];
                    min_color = i;
                }
            color[v] = min_color;
            Tracing(v,color[v]);
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
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int ans = INF, cl;
    FOR(i,1,max_color)
    {
        if (f[i][1] < ans) 
        {
            ans = f[i][1];
            cl = i;
        }
    }
    color[1] = cl;
    Tracing(1,cl);
    cout<<ans<<"\n";
    FOR(i,1,n) cout<<color[i]<<"\n";
}
