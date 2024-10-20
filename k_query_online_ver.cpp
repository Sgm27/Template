#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 30005
int n,q,a[maxn];
vector<int> t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) return t[id].push_back(a[l]), void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    merge(t[id*2].begin(),t[id*2].end(),t[id*2+1].begin(),t[id*2+1].end(),back_inserter(t[id]));
}
int get(int id,int l,int r,int u,int v,int k)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v)
        return t[id].size()-(upper_bound(t[id].begin(),t[id].end(),k)-t[id].begin());
    int m=(l+r)/2;
    return get(id*2,l,m,u,v,k)+get(id*2+1,m+1,r,u,v,k); 
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        int u,v,k;
        cin>>u>>v>>k;
        cout<<get(1,1,n,u,v,k)<<"\n";
    }
}

