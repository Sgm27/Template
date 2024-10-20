#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30004
int cnt,id[maxn],low[maxn],n,m;
vector<int> ke[maxn];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int  u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    
}

