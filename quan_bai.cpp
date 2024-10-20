#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
char a[105][105];
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) cin>>a[i][j];
	cin>>x>>y;
}
void in()
{
	for (int i=1;i<=2*n;i++)
	{
		for (int j=1;j<=2*m;j++) cout<<a[i][j];
		cout<<endl;
	}
}
void process()
{
	for (int j=1;j<=m;j++)
	{
		int dem=1,k=0;
		for (int i=n+1;i<=2*n;i++)
		{
			
			a[i][j]=a[i-dem][j];
			dem+=2;
		}
	}
	int dem=1,k=0;
	for (int j=m+1;j<=2*m;j++)
	{
		k++;
		for (int i=1;i<=2*n;i++) a[i][j]=a[i][j-dem];
		dem+=2;
	}
	if (a[x][y]=='#') a[x][y]='.'; else a[x][y]='#';
	in();

}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
