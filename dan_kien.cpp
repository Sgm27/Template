#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
bool hang[15],cot[15];
int main()
{
	memset(a,0,sizeof(a));
	memset(hang,true,sizeof(hang));
	memset(cot,true,sizeof(cot));
//	freopen("thu.inp","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			if (x=='S') 
			{
				hang[i]=false;
				cot[j]=false;
			}
		}
	for (int i=1;i<=n;i++)
		if (hang[i])
		{
			for (int j=1;j<=m;j++) a[i][j]=1;
		}
	for (int i=1;i<=m;i++)
		if (cot[i])
		{
			for (int j=1;j<=n;j++) a[j][i]=1;
		}
	int res=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) res+=a[i][j];
	cout<<res;
}
