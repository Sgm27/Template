#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,vis[10][10],a[10][10],res=0,ts=1;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void input()
{
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++) 
        {
            vis[i][j]=0;
            a[i][j]=1;
        }
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=0;
    }
}
void dfs(int i,int j)
{
    for (int k=0;k<=3;k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if (x>0 && x<=5 && y>0 && y<=5 && a[x][y] && !vis[x][y])
        {
            vis[x][y]=1;
            ts++;
            if (x==5 && y==5)
                if ()
            dfs(x,y);
            vis[x][y]=0;
            ts--;
        }
    }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    dfs(1,1);
    cout<<res;
}

