#include<iostream>
#include<math.h>
using namespace std;
using ll = long long;
#define maxn 50005
int a[maxn],st[17][maxn],n,q,m,lazy[maxn];
int get(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
void make_ST()
{
    for (int i=1;i<=n;i++) st[0][i]=a[i];
    for (int i=1;i<=log2(n);i++)
        for (int j=1;j<=(n-(1<<i)+1);j++)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        lazy[u]+=w;
        lazy[v+1]-=w;
    }
    int add=0;
    for (int i=1;i<=n;i++)
    {
        add+=lazy[i];
        a[i]=add;
    }
    make_ST();
    cin>>q;
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<get(u,v)<<"\n";
    }
}

