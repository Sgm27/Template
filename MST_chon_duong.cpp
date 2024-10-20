/*
    mỗi lần thêm một đương
    tìm MST sau mỗi lần thêm đó,nếu ko tồn tại in -1
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 505
int n,m,r[maxn];
struct mang{
    int u,v,w;
    void input()
    {
        cin>>u>>v>>w;
    }
};
mang a[maxn];
vector<mang> v;
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
    for (int i=1;i<=m;i++)
    {
        for (int i=1;i<=n;i++) r[i]=i;
        auto pos=lower_bound(v.begin(),v.end(),a[i],cmp);
        v.insert(pos,a[i]);
        vector<mang> next;
        int ans=0;
        for (mang x : v)
        {
            int ru=get(x.u);
            int rv=get(x.v);
            if (ru!=rv)
            {
                r[ru]=rv;
                ans+=x.w;
                next.push_back(x);
            }
        }
        if (next.size()==n-1) cout<<ans; else cout<<"-1";
        v=next;
        cout<<"\n";
    }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=m;i++) a[i].input();
    process();
}

