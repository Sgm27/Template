#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,trace[1005][1005],sum=0,res=1e9;

void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>trace[i][j];
}
void process()
{
	bool d[1005];
	memset(d,true,sizeof(d));
	int u=1; sum=0;
	d[1]=false;
	for (int k=1;k<n;k++)
	{
		ll Min=1e9,cs;
		for (int v=1;v<=n;v++)
			if (d[v] && trace[u][v] && trace[u][v]<Min)
			{
				Min=trace[u][v];
				cs=v;
			}
		sum+=Min;
		u=cs;
		d[u]=false;
	}
	cout<<sum+trace[u][1];
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
