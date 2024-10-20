#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int n,m,low[maxn],id[maxn],f[maxn],par[maxn],cnt,ans;
vector<int> ke[maxn];
void dfs(int u)
{
    low[u]=id[u]=++cnt;
    for (int v : ke[u])
        if (v!=par[u])
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                dfs(v);
                low[u]=min(low[u],low[v]);
                f[u]+=f[v];
                if (low[v]==id[v] && par[v]) ans+=f[v]*(n-f[v]);
            }
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    fill(f+1,f+1+n,1);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (!par[i])
        {
            dfs(i);
        }
    cout<<ans;
}

