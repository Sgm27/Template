#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 3003
string s1,s2;
int dp[maxn][maxn],n,m;
void process()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) 
            if (s1[i]!=s2[j]) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else dp[i][j]=dp[i-1][j-1]+1;
}
void Truyvet()
{
    int i=n,j=m,cs=dp[n][m],cnt=0,ans[maxn];
    while (i>=1 && j>=1 && cs)
    {
        while (dp[i][j-1]==cs) j--;
        while (dp[i-1][j]==cs) i--;
        cs--;
        ans[++cnt]=j;
        if (dp[i-1][j]==cs) i--;
        else 
        if (dp[i][j-1]==cs) j--;
    }
    for (int i=cnt;i>=1;i--) cout<<s2[ans[i]];
    if (!cnt) cout<<" ";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s1>>s2;
    if (s1.length()>s2.length()) swap(s1,s2);
    n=s1.length(); m=s2.length();
    s1=" "+s1; s2=" "+s2;
    process();
    Truyvet();
}

