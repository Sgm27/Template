#include <bits/stdc++.h>
using namespace std;
int n,a[105][105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			if (x=='.') a[i][j]=0;
			else a[i][j]=1;
		}
}
void process()
{
	int cnt,res=0;
	for (int i=1;i<=n;i++)
	{
		// xu ly hang
		cnt=0;
		for (int j=1;j<=n;j++) if (a[i][j]) cnt++;
		res+=cnt*(cnt-1)/2;
		// xu ly cot
		cnt=0;
		for (int j=1;j<=n;j++) if (a[j][i]) cnt++;
		res+=cnt*(cnt-1)/2;
	}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
