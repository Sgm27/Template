#include<iostream>
using namespace std;
int n,r[10005];
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
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=10000;i++) r[i]=i;
    for (int i=1;i<=n;i++)   
    {
        int u,v,q;
        cin>>u>>v>>q;
        if (q==2) 
        {
            u=get(u);
            v=get(v);
            cout<<(u==v)<<endl;
        } 
        else Union(u,v);
    }
}

