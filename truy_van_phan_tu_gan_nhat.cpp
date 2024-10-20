#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
#define maxn 200005
vector<int> t[maxn*4];
int a[maxn];
void build(int id,int l,int r)
{
    if (l==r) 
    {
        t[id].push_back(a[l]);
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    merge(t[id*2].begin(),t[id*2].end(),t[id*2+1].begin(),t[id*2+1].end(),back_inserter(t[id]));
}
int get_val(int id,int l,int r,int u,int v,int x)
{
    if (r<u || l>v) return 1e9;
    if (l>=u && r<=v)
    {
        auto it=lower_bound(t[id].begin(),t[id].end(),x);
        if (t[id].size()==1 || it==t[id].end()) return t[id].back();
        int tmp=lower_bound(t[id].begin(),t[id].end(),x)-t[id].begin()-1;
        if (tmp>=0 && abs(x-t[id][tmp])<=abs(*it-x)) return t[id][tmp];
        else return *it;
    }
    int m=(l+r)/2;
    int t1=get_val(id*2,l,m,u,v,x);
    int t2=get_val(id*2+1,m+1,r,u,v,x);
    if (abs(x-t1)==abs(x-t2)) return min(t1,t2);
    else
    if (abs(x-t1)<abs(x-t2)) return t1;
    else return t2;
}
int get_cnt(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) 
    {
        int tmp=lower_bound(t[id].begin(),t[id].end(),val)-t[id].begin();
        if (tmp==t[id].size() || t[id][tmp]!=val) return 0;
        int tmp1=upper_bound(t[id].begin(),t[id].end(),val)-t[id].begin()-1;
        return tmp1-tmp+1;
    }
    int m=(l+r)/2;
    int t1=get_cnt(id*2,l,m,u,v,val);
    int t2=get_cnt(id*2+1,m+1,r,u,v,val);
    return t1+t2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        int x,u,v;
        cin>>x>>u>>v;
        int val=get_val(1,1,n,u,v,x);
        cout<<val<<" "<<get_cnt(1,1,n,u,v,val)<<"\n";
    }
}

