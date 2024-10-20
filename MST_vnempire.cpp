#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 100005
struct point{
    int x,y,z,vertex;
    void input()
    {
        cin>>x>>y>>z;
    }
} a[maxn];
struct edges{
    int u,v,w;
} e[maxn*3];
int n,r[maxn],m;
int distance(point a,point b)
{
    return min({abs(a.x-b.x),abs(a.y-b.y),abs(a.z-b.z)});
}
void update(string type)
{
    if (type=="x")
        FOR(i,2,n) 
        {
            m++;
            e[m]={a[i-1].vertex,a[i].vertex,a[i].x-a[i-1].x};
        }
    if (type=="y")
        FOR(i,2,n) 
        {
            m++;
            e[m]={a[i-1].vertex,a[i].vertex,a[i].y-a[i-1].y};
        }
    if (type=="z")
        FOR(i,2,n) 
        {
            m++;
            e[m]={a[i-1].vertex,a[i].vertex,a[i].z-a[i-1].z};
        }
}
bool cmpx(point a,point b)
{
    return a.x<b.x;
}
bool cmpy(point a,point b)
{
    return a.y<b.y;
}
bool cmpz(point a,point b)
{
    return a.z<b.z;
}
bool cmp_edges(edges a,edges b)
{
    return a.w<b.w;
}
int get_root(int u)
{
    if (u==r[u]) return u;
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
void pre_process()
{
    sort(a+1,a+1+n,cmpx);
    update("x");
    sort(a+1,a+1+n,cmpy);
    update("y");
    sort(a+1,a+1+n,cmpz);
    update("z");
}
void Kruskal()
{
    int ans=0;
    FOR(i,1,n) r[i]=i;
    sort(e+1,e+1+m,cmp_edges);
    FOR(i,1,m)
    {
        int u=get_root(e[i].u);
        int v=get_root(e[i].v);
        if (join(u,v)) ans+=e[i].w;
    }
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) a[i].input(), a[i].vertex=i;
    pre_process();
    Kruskal();
}
