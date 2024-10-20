#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10004
const int add=1e9;
int a[maxn],n,dp[maxn],res=0;
vector<int> v;
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]+=add;
    }
}
void process()
{
    if (n<=2)
    {
        cout<<0;
        return;
    }
    sort(a+1,a+1+n);
    dp[1]=1; dp[2]=2;
    for (int i=3;i<=n;i++)
    {
        dp[i]=2;
        for (int j=2;j<i;j++) 
            if (dp[j]+1>dp[i] && binary_search(a+1,a+j,a[i]-a[j]+add)) dp[i]=dp[j]+1;
    }
    for (int i=1;i<=n;i++) res=max(res,dp[i]);
    cout<<res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

