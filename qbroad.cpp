#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int r[maxn],n,m,q,Q[maxn],d[maxn],ans[maxn];
struct data{
    int u,v;
    void input()
    {
        cin>>u>>v;
    }
};
data a[maxn];
int get_root(int u)
{
    if (r[u]==u) return u;
    return r[u]=get_root(r[u]);
}
void Union(int u,int v)
{
    u=get_root(u);
    v=get_root(v);
    r[u]=v;
}
void process()
{
    for (int i=1;i<=n;i++) r[i]=i;
    for (int i=1;i<=m;i++) 
        if (!d[i]) Union(a[i].u,a[i].v);
    memset(d,0,sizeof(d));
    int cnt_connect=0;
    for (int i=1;i<=n;i++) 
        if (i==get_root(i)) cnt_connect++;
    ans[q]=cnt_connect;
    for (int i=q;i>=1;i--)
    {
        int u=get_root(a[Q[i]].u);
        int v=get_root(a[Q[i]].v);
        if (u!=v)
        {
            r[u]=v;
            cnt_connect--;
        }
        ans[i-1]=cnt_connect;
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++) a[i].input();
    for (int i=1;i<=q;i++) cin>>Q[i], d[Q[i]]=1;
    process();
}

