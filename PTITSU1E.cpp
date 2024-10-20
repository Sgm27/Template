#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int x[25],vis[25],d[25][25],res,n,m;
void dfs(int u)
{
    vis[u]=1;
    for (int v=1;v<=n;v++)
        if (x[v] && d[u][v] && !vis[v])
            dfs(v);
}
void Update()
{
    for (int i=1;i<=n;i++) vis[i]=0;
    dfs(1);
    if (!vis[2]) return;
    for (int i=1;i<=n;i++) vis[i]=0;
    dfs(2);
    if (!vis[1]) return;
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (x[i]) cnt++;
    res=min(res,cnt);
}
void Try(int i)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        if (i==n) Update();
        else Try(i+1);
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--)
    {
        res=1e7;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) d[i][j]=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            d[x][y]=1;
        }
        x[1]=1;
        x[2]=1;
        Try(3);
        cout<<res<<endl;
    }
}

