#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
#define maxn 1005
int h[maxn],n;
vector<int> ke[maxn];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
    }
    h[0]=-1;
}
void dfs(int u,int p)
{
    h[u]=h[p]+1;
    for (int v : ke[u])
        dfs(v,u);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<h[i]<<" ";
}

