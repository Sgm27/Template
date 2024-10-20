#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[1005][1005],tonghang[1005][1005],tongcot[1005][1005];
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
}
void init()
{
	for (int i=1;i<=n;i++) tonghang[i][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) tonghang[i][j]=tonghang[i][j-1]+a[i][j];
	}
	for (int i=1;i<=m;i++) tongcot[0][i]=0;
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++) tongcot[i][j]=tongcot[i-1][j]+a[i][j];
	}
}
void process()
{
	ll q;
	cin>>q;
	ll x,y,z,t;
	while (q--)
	{
		cin>>x>>y>>z>>t;
		if (x==2)
		{
			cout<<tongcot[t][y]-tongcot[z-1][y]<<endl;
		}
		else cout<<tonghang[y][t]-tonghang[y][z-1]<<endl;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	init();
	process();
}
