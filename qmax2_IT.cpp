#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 50005
int n,t[maxn*4],lazy[maxn*4];
void Push(int id)
{
    t[id*2]+=lazy[id];
    t[id*2+1]+=lazy[id];
    lazy[id*2]+=lazy[id];
    lazy[id*2+1]+=lazy[id];
    lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,int w)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        t[id]+=w;
        lazy[id]+=w;
        return;
    }
    if (lazy[id]) Push(id);
    int m=(l+r)/2;
    update(id*2,l,m,u,v,w);
    update(id*2+1,m+1,r,u,v,w);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return -1e9;
    if (l>=u && r<=v) return t[id];
    if (lazy[id]) Push(id);
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin>>n>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (!type)
        {
            int u,v,k;
            cin>>u>>v>>k;
            update(1,1,n,u,v,k);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            cout<<get(1,1,n,u,v)<<"\n";
        }
    }
}

