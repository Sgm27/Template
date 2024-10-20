#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int a[105][105],n,m,d[105][105];
void input()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char x;
            cin>>x;
            if (x=='.') a[i][j]=0;
            else a[i][j]=1;
            d[i][j]=0;
        }
}
void bfs(int i,int j)
{
    queue<int> qx;
    queue<int> qy;
    qx.push(i);
    qy.push(j);
    d[i][j]=1;
    while (!qx.empty())
    {
        int x=qx.front();
        int y=qy.front();
        qx.pop();
        qy.pop();
        for (int k=0;k<=3;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if (xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy] && !d[xx][yy])
            {
                d[xx][yy]=1;
                qx.push(xx);
                qy.push(yy);
            }
        }
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cnt=0;
    input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j] && !d[i][j])
            {
                cnt++;
                bfs(i,j);
            }
    cout<<cnt;
}

