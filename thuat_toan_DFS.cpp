#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
vector<int> ke[1005];
int n,m,u,d[1005];
void input()
{
    cin>>n>>m>>u;
    for (int i=1;i<=n;i++) d[i]=1;
    for (int i=1;i<=n;i++) ke[i].clear();
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void dfs(int u)
{
    d[u]=0;
    cout<<u<<" ";
    for (int k : ke[u]) 
        if (d[k])
        {
            dfs(k);
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        input();	
        dfs(u);
        cout<<endl;
    }
}

