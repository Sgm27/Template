#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 305
struct mang{
    int u,v,w;
} a[maxn*maxn];
int n,m,ans,r[maxn];
bool cmp(mang a,mang b)
{
    return a.w<b.w;
}
int get_root(int u)
{
    if (r[u]==u) return u;
    return r[u]=get_root(r[u]);
}
bool join(int u,int v)
{
    u=get_root(u); v=get_root(v);
    if (u==v) return false;
    r[u]=v;
    return true;
}
void process()
{
    FOR(i,1,n) r[i]=i;
    sort(a+1,a+1+m,cmp);
    FOR(i,1,m)
    {
        int u=get_root(a[i].u);
        int v=get_root(a[i].v);
        if (join(u,v)) ans+=a[i].w;
    }
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
    {
        int tmp; cin>>tmp;
        ++m;
        a[m].u=0;
        a[m].v=i;
        a[m].w=tmp;
    }
    FOR(i,1,n)
        FOR(j,1,n)
        {
            int cost; cin>>cost;
            ++m;
            a[m].u=i;
            a[m].v=j;
            a[m].w=cost;
        }
    process();
}
