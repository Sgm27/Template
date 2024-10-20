#include <bits/stdc++.h>
using namespace std;
int n,s,a[10000],dp[10000]={0};
void nhap()
{
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void xuly()
{
    for (int i=1;i<=n;i++)
    {
        dp[a[i]]=1;
        for (int j=s;j>=a[i];j--)
            if (dp[j-a[i]]==1) dp[j]=1;
    }
    if (dp[s]==1) cout<<"YES\n";
    else cout<<"NO\n";
}
void truyvet()
{
    //while ()
}
int main()
{
    freopen("thu.inp","r",stdin);
    nhap();
    xuly();
}
