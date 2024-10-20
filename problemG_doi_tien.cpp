#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int dp[100105],n,s,a[maxn],Max=-1;
void input()
{
    cin>>n>>s;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        Max=max(Max,a[i]);
    }
}
void process()
{
    int moc=100000,res=0;
    if (s>moc)
    {
        int hieu=s-moc;
        res+=hieu/Max;
        s=s-hieu/Max*Max;
    }
    for (int i=0;i<=s;i++) dp[i]=INT_MAX;
    dp[0]=0;
    for (int j=1;j<=s;j++)
        for (int i=1;i<=n;i++)
            if (j>=a[i]) dp[j]=min(dp[j],dp[j-a[i]]+1);
    cout<<res+dp[s];
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

