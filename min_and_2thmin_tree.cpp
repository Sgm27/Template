#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30004 
int n,m,r[maxn];
struct mang{
    int u,v,w;
};
mang a[maxn];
vector<int> idx;
int get(int u)
{
    if (r[u]==u) return u;
    else return r[u]=get(r[u]);
}
void Union(int u,int v)
{
    u=get(u);
    v=get(v);
    r[v]=u;
}
bool cmp(mang a,mang b)
{
    return a.w<b.w;
}
void process()
{
    sort(a+1,a+1+m,cmp);
    int ans1=0,ans2=1e9;
    for (int i=1;i<=n;i++) r[i]=i;
    for (int i=1;i<=m;i++)
    {
        int ru=get(a[i].u);
        int rv=get(a[i].v);
        if (ru!=rv)
        {
            r[ru]=rv;
            ans1+=a[i].w;
            idx.push_back(i);
        }
    }
    for (int check : idx)
    {
        int sum=0,count=0;
        for (int i=1;i<=n;i++) r[i]=i;
        for (int i=1;i<=m;i++)
            if (i!=check)
            {
                int ru=get(a[i].u);
                int rv=get(a[i].v);
                if (ru!=rv)
                {
                    r[ru]=rv;
                    sum+=a[i].w;
                    count++;
                }
            }
        if (count==n-1) ans2=min(ans2,sum);
    }
    cout<<ans1<<" "<<ans2;
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
    }
    process();
}

