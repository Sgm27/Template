#include <bits/stdc++.h>
using namespace std;
int n,a[55][55];
bool dd[55][55];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void nhap()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
	{
		char x;
		cin>>x;
		if (x=='#') 
		{
			a[i][j]=1;
			dd[i][j]=false;
		}
		else a[i][j]=0;
	}
}
void xuly()
{
	for (int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if (a[i][j]==0 && dd[i][j]==true)
		{
			dd[i][j]=false;
			bool ok=true;
			for (int k=0;k<=3;k++)
			{
				int xx=i+dx[k];
				int yy=j+dy[k];
				if (a[xx][yy]==0 && dd[xx][yy]==true && xx>=1 && xx<=n && yy>=1 && yy<=n) continue;
				else 
				{
					ok=false;
					break;
				}
			}
			if (ok) 
				for (int k=0;k<=3;k++)
			{
				int xx=i+dx[k];
				int yy=j+dy[k];
				dd[xx][yy]=false;
			}
			if (!ok) dd[i][j]=true;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (dd[i][j]) 
		{
			cout<<"NO";
			return;
		}
	cout<<"YES";
}
int main()
{
	memset(dd,true,sizeof(dd));
//	freopen("thu.inp","r",stdin);
	nhap();
	xuly();
}
