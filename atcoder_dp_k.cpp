#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 500005
int n,k,dp[maxn],a[105];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++)
            if (i>=a[j])
            {
                if (!dp[i-a[j]]) dp[i]=1;
            }
    if (dp[k]) cout<<"First"; else cout<<"Second";
}

