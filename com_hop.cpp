#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,a[105][105];
void process()
{
	int Min=INT_MAX;
	int x,y,kc;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			kc=0;
			for (int x=1;x<=n;x++)
			{
				for (int y=1;y<=m;y++)	
				{
					kc+=(abs(x-i)+abs(y-j))*(a[x][y]);
					if (kc>Min) break;
				}
				if (kc>Min) break;
			}
			Min=min(Min,kc);
		}
	cout<<Min<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>m>>n;
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=m;j++) cin>>a[i][j];
		process();
	}
}
