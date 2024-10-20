#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 20000005
int n,q,a[25],dp[maxn],S=0;
void process()
{
    dp[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=S;j>=a[i];j--)
            if (dp[j-a[i]]) dp[j]=1;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        S+=a[i];
    }
    process();
    while (q--)
    {
        int x;
        cin>>x;
        cout<<dp[x];
    }
}

