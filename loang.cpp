#include <bits/stdc++.h>
using namespace std;
int n,a[1000][1000];
bool d[1000][1000];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void nhap()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			if (x=='o') a[i][j]=0;
			else a[i][j]=1;
		}

}
void bfs(int i,int j)
{
	queue<int> qx;
	queue<int> qy;
	qx.push(i);
	qy.push(j);
	int x,y,xx,yy;
	d[i][j]=true;
	while (!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for (int k=0;k<=3;k++)
		{
			xx=x+dx[k];
			yy=y+dy[k];
			if (xx>0 && xx<=n && yy>0 && yy<=n && a[xx][yy]==0 && d[xx][yy]==false)
			{
				d[xx][yy]=true;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	memset(d,false,sizeof(d));
	nhap();
	for (int i=1;i<=n;i++)
		{
			if (a[1][i]==0 && d[1][i]==false) bfs(1,i);
			if (a[i][1]==0 && d[i][1]==false) bfs(i,1);
			if (a[n][i]==0 && d[n][i]==false) bfs(n,i);
			if (a[i][n]==0 && d[i][n]==false) bfs(i,n);
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (d[i][j]) cout<<"o "; else cout<<"x ";
		cout<<endl;
	}
}
