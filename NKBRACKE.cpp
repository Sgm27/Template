#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
char a[maxn];
struct node{
    int op,cl;
};
node t[maxn*4];
node Merge(node l,node r)
{
    int tmp=min(l.op,r.cl);
    return {l.op+r.op-tmp,l.cl+r.cl-tmp};
}
void build(int id,int l,int r)
{
    if (l==r) 
    {
        if (a[l]=='(') return t[id]={1,0}, void();
        else return t[id]={0,1}, void();
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p,char x)
{
    if (l>p || r<p) return;
    if (l==r)
    {
        if (x=='(') t[id]={1,0};
        else t[id]={0,1};
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,x);
    update(id*2+1,m+1,r,p,x);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
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
        int type;
        cin>>type;
        if (type==1)
        {
            int u,v;
            cin>>u>>v;
            node tmp=get(1,1,n,u,v);
            if (tmp.op==0 && tmp.cl==0) cout<<1;
            else cout<<0;
        }
        else 
        {
            int p; char x;
            cin>>p>>x;
            update(1,1,n,p,x);
        }
    }
}

