#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],r[maxn],n,q,lab[maxn];
vector<map<int,int>> color;
int get_root(int u)
{
    if (u==r[u]) return u;
    return r[u]=get_root(r[u]);
}
void Union(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    if (u==v) return;
    if (lab[u]<lab[v]) swap(u,v);
    r[v]=u;
    lab[u]+=lab[v];
    for (auto x : color[v]) color[u][x.first] += x.second;
    color[v].clear();
}
int getColor(int u,int c)
{
    u=get_root(u);
    if (color[u].find(c)==color[u].end()) return 0;
    return color[u][c];
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    color.resize(n+1);
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        color[i][a[i]]++;
        lab[i]=1;
        r[i]=i;
    }
    while (q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if (type==1)
            Union(u,v);
        else
            cout<<getColor(u,v)<<"\n";
    }
}

