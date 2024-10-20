#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
struct node{
    int Max,op,cl;
};
node t[maxn*4];
int n;
string s;
void build(int id,int l,int r)
{
    if (l==r)
    {
        if (s[l]=='(') t[id]={0,1,0};
        else t[id]={0,0,1};
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    // merge node
    int tmp=min(t[id*2].op,t[id*2+1].cl);
    int open=t[id*2].op+t[id*2+1].op-tmp;
    int close=t[id*2].cl+t[id*2+1].cl-tmp;
    int ma=t[id*2].Max+t[id*2+1].Max+tmp*2;
    t[id]={ma,open,close};
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    int tmp=min(t1.op,t2.cl);
    int open=t1.op+t2.op-tmp;
    int close=t1.cl+t2.cl-tmp;
    int ma=t1.Max+t2.Max+tmp*2;
    return {ma,open,close};
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    n=s.length();
    s="#"+s;
    build(1,1,n);
    int q;
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<get(1,1,n,u,v).Max<<"\n";
    }
}

