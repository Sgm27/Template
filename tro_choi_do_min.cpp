#include <bits/stdc++.h>
using namespace std;
int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
int n,m;
char a[105][105];
int domin(int i,int j)
{
	int cnt=0;
	for (int k=0;k<=7;k++)
	{
		int xx=i+dx[k];
		int yy=j+dy[k];
		if (xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy]=='*') cnt++;
	}
	return cnt;
}
void process()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]=='.') cout<<domin(i,j); else cout<<"*";
		}
		cout<<endl;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>n>>m)
	{
		if (n==0 && m==0) return 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) cin>>a[i][j];
		process();
	}
}
