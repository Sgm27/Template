#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][55];
bool check[55][55];
int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char x; cin>>x;
			if (x=='.') a[i][j]=0;
			else a[i][j]=1;
		}
}
int loang(int i,int j)
{
	int x,y;
	int res=0;
	for (int k=0;k<=7;k++)
	{
		x=i+dx[k];
		y=j+dy[k];
		if (x>0 && x<=n && y>0 && y<=m) res+=a[x][y];
	}
	return res;
}
int bfs(int i,int j)
{
	int x,y;
	int res=0;
	for (int k=0;k<=7;k++)
	{
		x=i+dx[k];
		y=j+dy[k];
		if (x>0 && x<=n && y>0 && y<=m) res+=a[x][y];
	}
	return res;
}
void process()
{
	int Max=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			if (a[i][j]==0) Max=max(Max,loang(i,j));
	int tong=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==1) tong+=bfs(i,j);
		}
	cout<<Max+tong/2;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	memset(a,0,sizeof(a));
	memset(check,true,sizeof(check));
	input();
	process();
}
