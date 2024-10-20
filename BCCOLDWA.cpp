#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
#define maxn 100005
int h[maxn],n,m;
vector<int> ke[maxn];
void input()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++) 
    {
        int x,y,z;
        cin>>x>>y>>z;
        ke[x].push_back(y);
        ke[x].push_back(z);
    }
    h[0]=0;
}
void dfs(int u,int p)
{
    h[u]=h[p]+1;
    for (int v : ke[u])
        dfs(v,u);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<h[i]<<"\n";
}

