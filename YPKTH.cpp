#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn];
vector<int> t[maxn*4];
void build(int id,int l,int r)
{
    if (l==r) return t[id].push_back(a[l]), void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    merge(t[id*2].begin(),t[id*2].end(),t[id*2+1].begin(),t[id*2+1].end(),back_inserter(t[id]));
}
int get(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) 
    {
        int x=upper_bound(t[id].begin(),t[id].end(),val)-t[id].begin();
        return x;
    }
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v,val);
    int t2=get(id*2+1,m+1,r,u,v,val);
    return t1+t2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        int u,v,k,ans=-1;
        cin>>u>>v>>k;
        int l=-1e9,r=1e9;
        while (r-l>1)
        {
            int m=(l+r)/2;
            int x=get(1,1,n,u,v,m);
            if (x>=k) 
            {
                if (x==k) ans=m;
                r=m;
            }
            else l=m; 
        }
        cout<<ans<<"\n";
    }
}

