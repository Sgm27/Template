#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,S,dp[maxn],a[maxn];
void process()
{
    int res=0;
    dp[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=S;j>=a[i];j--)
            if (dp[j-a[i]]) 
            {
                dp[j]=1;
                if (j<=S && j>res) res=j;
            }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>S;
    for (int i=1;i<=n;i++) cin>>a[i];
    process();
}

