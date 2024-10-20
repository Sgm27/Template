#include <bits/stdc++.h>
using namespace std;
int n,m,a[35][35],b[10005],q;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			if (x=='.') a[i][j]=0;
			else a[i][j]=-1;
		}
	cin>>q;
	for (int i=1;i<=q;i++) cin>>b[i];
}
void rao_bien()
{
	for (int i=1;i<=n+1;i++) 
	{
		a[i][0]=-1;
		a[i][m+1]=-1;
	}
	for (int i=1;i<=m;i++) a[n+1][i]=-1;
}
void in()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) 
			if (a[i][j]==0) cout<<'.';
			else if (a[i][j]==1) cout<<'O';
			else cout<<'X';
		cout<<endl;
	}
}
void process()
{
	rao_bien();
	int dem=0;
	for (int i=1;i<=q;i++)
	{
		int cot=b[i],stop=0,idx=0;
		while (!stop)
		{
			if (a[idx+1][cot]==0)
			{
				idx++;
				continue;
			}
			if (a[idx+1][cot]==-1) 
			{
				a[idx][cot]=1;
				break;
			}
			if (a[idx+1][cot]==1)
			{
				if (a[idx+1][cot-1]==0 && a[idx][cot-1]==0) 
				{
					idx++;
					cot--;
				}
				else
				if (a[idx+1][cot+1]==0 && a[idx][cot+1]==0)
				{
					idx++;
					cot++;
				}
				else
				{
					a[idx][cot]=1;
					break;
				}
			}
		}
	}
	in();
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
