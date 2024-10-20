#include <bits/stdc++.h>
using namespace std;
int n,a[10000],dp[10000];
void nhap()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void xuly()
{
    int res=-1;
    for (int i=1;i<=n;i++)
    {
        dp[i]=1;
        for (int j=1;j<i;j++)
            if (a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
        res=max(res,dp[i]);
    }
    cout<<res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    nhap();
    xuly();
}
