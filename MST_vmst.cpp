#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 1505
int r[maxn],n,m;
struct data{
    int u,v,id;
} a[maxn];
vector<vector<data>> res;
int get_root(int u)
{
    if (u==r[u]) return u;
    return r[u]=get_root(r[u]);
}
bool join(int u,int v)
{
    u=get_root(r[u]);
    v=get_root(r[v]);
    if (u==v) return false;
    r[u]=v;
    return true;
}
void process()
{
    FOR(i,1,n) r[i]=i;
    vector<data> tmp;
    int num_MST=0;
    int edges=0;
    FOR(i,1,m)
    {
        int u=get_root(a[i].u);
        int v=get_root(a[i].v);
        if (join(u,v)) 
        {
            edges++;
            tmp.push_back(a[i]);
        }
    }
    if (edges!=n-1) return cout<<0, void();
    res.push_back(tmp);
    for (data x : tmp)
    {
        vector<data> next;
        FOR(i,1,n) r[i]=i;
        FOR(i,1,m) 
            if (i!=x.id)
            {
                int u=get_root(a[i].u);
                int v=get_root(a[i].v);
                if (join(u,v)) next.push_back(a[i]);
            }
        if (next.size()==n-1) res.push_back(next);
        if (res.size()==3) break;
    }
    cout<<res.size()<<"\n";
    for (auto v : res)
        for (data x : v) cout<<x.u<<" "<<x.v<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,m) cin>>a[i].u>>a[i].v, a[i].id=i;
    process();
}
