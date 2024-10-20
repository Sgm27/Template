#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int d[105][105],a[105][105];
int n,m,mc,tt=0;
void bfs1(int i,int j)
{
	queue<int> qx;
	queue<int> qy;
	qx.push(i);
	qy.push(j);
	d[i][j]=a[i][j];
	int x,y,xx,yy;
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
			if (xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy]<=a[i][j] && d[xx][yy]<a[i][j])
			{
				d[xx][yy]=a[i][j];
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
bool bfs2(int i,int j)
{
	queue<int> qx;
	queue<int> qy;
	qx.push(i);
	qy.push(j);
	d[i][j]=mc;
	int x,y,xx,yy;
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
			if (xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy]>mc& d[xx][yy]) <mc
			{
				d[xx][yy]=mc;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
void process(int n,int m)
{
	cout<<"Case "<<tt<<": ";
	int Min=INT_MAX;
	int Max=INT_MIN;
	for (int i=1;i<=n;i++) 
	{
		Min=min(Min,min(a[i][1],a[i][m]));
		Max=max(Max,max(a[i][1],a[i][m]));
	}
	for (int i=1;i<=m;i++)
	{
		Min=min(Min,min(a[1][i],a[n][i]));
		Max=max(Max,max(a[1][i],a[n][i]));
	}
	for (int i=Min;i<=Max;i++)
	{
		bool ok=false;
		for (int j=1;j<=n;j++) 
			{
				if (a[j][1]==i) 
				{
					bfs1(j,1);
					ok=true;
				}
				if (a[j][m]==i)
				{
					bfs1(j,m);
					ok=true;
				}
			}
		for (int j=1;j<=m;j++)
			{
				if (a[1][j]==i)
				{
					bfs1(1,j);
					ok=true;
				}
				if (a[n][j]==i)
				{
					bfs1(n,j);
					ok=true;
				}
			}
		if (ok)
		{
			int cnt=0;
			mc=i;
			for (int j=1;j<=n;j++)
				for (int k=1;k<=m;k++)
					if (a[j][k]>mc && d[j][k]!=mc) 
					{
						cnt++;
						if (cnt>1) 
						{
							cout<<"Island splits when ocean rises "<<i<<" feet."<<endl;
							return;
						}
						bfs2(j,k);
					}
		}
	}
	cout<<"Island never splits."<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	while (1)
	{
		cin>>n>>m;
		tt++;
		if(n==0 && m==0) return 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) d[i][j]=-1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) cin>>a[i][j];
		process(n,m);
	}
}
