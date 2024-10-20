#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105];
bool d[105][105];
int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			if (x=='.') a[i][j]=1;
			else a[i][j]=0;
		}
}
void bfs(int i,int j)
{
	queue<int> qx;
	queue<int> qy;
	qx.push(i);
	qy.push(j);
	d[i][j]=false;
	int x,y,xx,yy;
	while (!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for (int k=0;k<=7;k++)
		{
			xx=x+dx[k];
			yy=y+dy[k];
			if (xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy]==0 && d[xx][yy])
			{
				d[xx][yy]=false;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
void process()
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (d[i][j] && a[i][j]==0) 
			{
				bfs(i,j);
				cnt++;
			}
	cout<<cnt;
}
int main()
{
	memset(d,true,sizeof(d));
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
