#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define maxn 100005
int n,a[maxn],m,deg[maxn],d[maxn];
vector<pii> ke[maxn];
void process()
{
    queue<int> Q;
    for (int i=1;i<=n;i++)
        if (!deg[i]) Q.push(i);
    while (!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for (pii x : ke[u])
        {
            int v=x.first;
            int w=x.second;
            if (d[v]<d[u]+w) d[v]=d[u]+w;
            deg[v]--;
            if (!deg[v]) Q.push(v);
        }
    }
} 
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ke[u].push_back({v,w});
        deg[v]++;
    }
    process();
    cout<<*max_element(d+1,d+1+n);
}

