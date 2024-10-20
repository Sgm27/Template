#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum=0,n,c,a[20],res=0;
void Try(int i)
{
    for (int j=0;j<=1;j++)
        if (sum+a[i]*j<=c)
    {
        sum+=a[i]*j;
        if (i==n) res=max(res,sum);
        else Try(i+1);
        sum-=a[i]*j;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>c>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    Try(1);
    cout<<res;
}


