#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int a[maxn],dp[100006],n,s;
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    dp[0]=1;
    for (int j=1;j<=s;j++)
        for (int i=1;i<=n;i++)
            if (j>=a[i] && dp[j-a[i]]) dp[j]+=dp[j-a[i]];
    cout<<dp[s];
}

