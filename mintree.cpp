#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30004 
int n,m,r[maxn];
struct mang{
    int u,v,w;
};
vector<mang> res;
mang a[maxn];
int get(int u)
{
    if (r[u]==u) return u;
    else return r[u]=get(r[u]);
}
bool cmp(mang a,mang b)
{
    return a.w<b.w;
}
void process()
{
    sort(a+1,a+1+m,cmp);
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int ru=get(a[i].u);
        int rv=get(a[i].v);
        if (ru!=rv)
        {
            r[ru]=rv;
            ans+=a[i].w;
            res.push_back(a[i]);
        }
    }
    cout<<ans<<"\n";
    for (mang k : res)
        cout<<k.u<<" "<<k.v<<"\n";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        r[i]=i;
    }
    process();
}

