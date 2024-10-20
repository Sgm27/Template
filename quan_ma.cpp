#include<iostream>
using namespace std;
using ll = long long;
int n,m,a[105][105],dp[105][105];
int dx[4]={-1,-2,-2,-1};
int dy[4]={-2,-1,1,2};
void input()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
}
void process()
{
    for (int i=1;i<=m;i++) dp[1][i]=a[1][i];
    for (int i=2;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int Max=0;
            for (int k=0;k<=3;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if (x>=1 && y>=1 && x<=n && y<=m) Max=max(dp[x][y],Max);
            }
            dp[i][j]=Max+a[i][j];
        }
    int res=0;
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) res=max(res,dp[i][j]);
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

