#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 15005
int n,m,r[maxn];
struct mang{
    int u,v,w;
    void input()
    {
        cin>>u>>v>>w;
    }
} a[maxn];
bool cmp(mang x,mang y)
{
    return x.w<y.w;
}
int get_root(int u)
{
    if (r[u]==u) return u;
    return r[u]=get_root(r[u]);
}
bool join(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    if (u==v) return false;
    r[u]=v;
    return true;
}
void build_MST()
{
    int ans=0;
    sort(a+1,a+1+m,cmp);
    for (int i=1;i<=n;i++) r[i]=i;
    for (int i=1;i<=m;i++)
    {
        int u=get_root(a[i].u);
        int v=get_root(a[i].v);
        if (join(u,v))
            ans+=a[i].w;
    }
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++) a[i].input();
    build_MST();
}

