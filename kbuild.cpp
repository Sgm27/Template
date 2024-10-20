#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
int cnt,n,low[maxn],id[maxn],par[maxn],bridge;
vector<int> ke[maxn];
unordered_map<int,int> flag[maxn];
void dfs(int u)
{
    id[u]=low[u]=++cnt;
    for (int v : ke[u])
        if (par[u]!=v)
        {
            if (id[v]) low[u]=min(low[u],id[v]);
            else
            {
                par[v]=u;
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v]==id[v] && !flag[min(u,v)][max(u,v)]) bridge++;
            }
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n-1;i++) 
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
        flag[min(u,v)][max(u,v)]=1;
    }
    par[1]=-1;
    dfs(1);
    cout<<bridge;
}

