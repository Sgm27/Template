#include <bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int main()
{
    freopen("thu.inp","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,0,sizeof(dp));
	int res=-1;
    for (int i=1;i<=s1.size();i++)
        for (int j=1;j<=s2.size();j++)
    {
        if (s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        res=max(res,dp[i][j]);
    }
    cout<<res;
    return 0;
}
