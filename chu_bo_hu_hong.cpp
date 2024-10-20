#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool vis[N];
vector<int>g[N];
queue<int>q;
int n,m,cnt;
void BFS(int x)
{
    q.push(x);
    vis[x]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main()
{
//	freopen("thu.inp","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<i<<endl;
            cnt=1;
        }
    }
    if(!cnt) cout<<0<<endl;
    return 0;
}
