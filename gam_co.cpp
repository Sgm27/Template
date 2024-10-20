#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char a[105][105];
int n,m,sx,sy,ex,ey,d[105][105];
void input()
{
    memset(d,0,sizeof(d));
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='B') 
            {
                ex=i;
                ey=j;
            }
            if (a[i][j]=='C')
            {
                sx=i;
                sy=j;
            }
        }
}
void bfs(int i,int j)
{
    if (sx==ex && sy==ey) 
    {
        cout<<"0";
        return;
    }
    queue<int> qx;
    queue<int> qy;
    qx.push(i);
    qy.push(j);
    d[i][j]=0;
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
            if (xx>0 && xx<=n && yy>0 && yy<=m && !d[xx][yy] && a[xx][yy]!='*')
            {
                d[xx][yy]=d[x][y]+1;
                if (d[ex][ey])
                {
                    cout<<d[ex][ey];
                    return;
                }
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
    input();
    bfs(sx,sy);
}

