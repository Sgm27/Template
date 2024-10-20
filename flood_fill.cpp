#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
int a[55][55];
bool d[55][55];
set<int> se;
multiset<int> kq;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
		{
			cin>>a[i][j];
			se.insert(a[i][j]);
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
	int dem=1;
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
			if (xx>0 && xx<=n && yy>0 && yy<=m && d[xx][yy] && a[xx][yy]==a[i][j])
			{
				dem++;
				d[xx][yy]=false;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
	kq.insert(dem);
}
void process()
{
	for (int x : se)
	{
		cout<<x<<" : ";
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			if (d[i][j] && a[i][j]==x) bfs(i,j);
		for (int k : kq) cout<<k<<" ";
		cout<<endl;
		kq.clear();
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	memset(d,true,sizeof(d));
	input();
	process();
}
