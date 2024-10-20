#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,k,a[1005],d[1005],vis[1005];
vector<int> ke[1005];
void input()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
    }
}
void bfs(int i)
{
    for (int i=1;i<=m;i++) vis[i]=0;
    d[i]++;
    vis[i]=1;
    stack<int> S;
    S.push(i);
    while (!S.empty())
    {
        int x=S.top();
        S.pop();
        for (int k : ke[x])
            if (!vis[k])
        {
            vis[k]=1;
            d[k]++;
            S.push(k);
        }
    }
}
void process()
{
    int res=0;
    for (int i=1;i<=m;i++)
        if (d[i]==n) 
        {
            res++;
        }
    cout<<res;
}
int main()
{
    memset(d,0,sizeof(d));
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    for (int i=1;i<=n;i++) bfs(a[i]);
    process();
}

