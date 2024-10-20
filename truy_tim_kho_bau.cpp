#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,d[10005],vis[10005],trace[10005];
bool check_res=false;
vector<int> ke[10005];
void dfs(int u)
{
    vis[u]=1;
    for (int k : ke[u]) d[k]--;
    for (int v=1;v<=n;v++)
        if (!vis[v] && d[v]==0) 
        {
            dfs(v);
            for (int x : ke[v]) d[x]++;
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--)
    {
        for (int i=1;i<=n;i++) ke[i].clear();
        for (int i=1;i<=n;i++) d[i]=0;
        cin>>n>>m;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            d[y]++;
            ke[x].push_back(y);
        }
        for (int i=1;i<=n;i++)
            if (d[i]==0) 
            {
                for (int i=1;i<=n;i++) vis[i]=0;
                dfs(i);
            }
    }
}

