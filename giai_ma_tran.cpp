#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
ll n,a[maxn][maxn],res[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) 
            cin>>a[i][j];
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]!=a[j][i]) 
            {
                cout<<"-1";
                return 0;
            }
        }
    ll tmp1=a[1][3]-a[1][2];
    ll tmp2=a[2][3];
    if ((tmp2+tmp1)%2!=0)
    {
        cout<<"-1";
        return 0;
    }
    res[3]=(tmp2+tmp1)/2;
    for (int i=1;i<=n;i++)
        if (i!=3)
        {
            res[i]=a[i][3]-res[3];
        }
    for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}

