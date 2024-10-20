#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1005
int n,m,q,trace[maxn][maxn],d[maxn][maxn];
struct edges{
    int u,v,w;
} e[maxn];
void init_trace()
{
    FOR(u,1,n)
        FOR(v,1,n) trace[u][v]=u;
}
void floyd()
{
    FOR(k,1,n)
        FOR(u,1,n)
            FOR(v,1,n) 
                if (d[u][v]>d[u][k]+d[k][v])
                {
                    d[u][v]=d[u][k]+d[k][v];
                    trace[u][v]=trace[k][v];
                }
}
void tracing(int u,int v)
{
    vector<int> path;
    while (v!=u) path.push_back(v), v=trace[u][v];
    path.push_back(u);
    reverse(path.begin(),path.end());
    if (path.size()==1)
    {
        cout<<2<<" "<<path.back()<<" "<<path.back()<<"\n";
        return;
    }
    cout<<path.size()<<" ";
    for (int x : path) cout<<x<<" ";
    cout<<"\n";
}
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>q;
    FOR(i,1,n) FOR(j,1,n) d[i][j]=1e18;
    FOR(i,1,m) 
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    init_trace();
    floyd();
    int num=0;
    while (q--)
    {
        // cout<<++num<<" ";
        int type,u,v;
        cin>>type>>u>>v;
        if (!type) 
        {
            if (u!=v && d[u][v]!=1e18) cout<<d[u][v]<<"\n";
            else cout<<"0\n";
        }
        else 
            if (u!=v) tracing(u,v);
    }
}
