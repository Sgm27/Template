#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[1005][1005];
void input()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
}
void init()
{
    for (int i=0;i<=n;i++) 
    {
        a[i][0]=0;
        a[i][m+1]=0;
    }
    for (int i=0;i<=m;i++)
    {
        a[0][i]=0;
        a[n+1][i]=0;
    }
}
void process()
{
    ll res=n*m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]>a[i-1][j]) res+=(a[i][j]-a[i-1][j]);
            if (a[i][j]>a[i+1][j]) res+=(a[i][j]-a[i+1][j]);
            if (a[i][j]>a[i][j-1]) res+=(a[i][j]-a[i][j-1]);
            if (a[i][j]>a[i][j+1]) res+=(a[i][j]-a[i][j+1]);
        }
    cout<<res;
}
int main()
{
   // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    init();
    process();
}

