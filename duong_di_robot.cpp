#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=2147483647;
ll n,a[1005][1005],dp[1005][1005],res;
bool d[1005][1005];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
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
ll qhd()
{
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=n+1;j++) dp[i][j]=0;
	if (a[n][n]==0) dp[n][n+1]=1;
	int j=n;
	while (j>0)
	{
		for (int i=n;i>=1;i--) 
			if (a[i][j]==0) dp[i][j]=(dp[i+1][j]+dp[i][j+1])%MOD;
		j--;
	}
	return dp[1][1];
}
bool checkgamelie()
{
	queue<int> qx;
	queue<int> qy;
	qx.push(1);
	qy.push(1);
	d[1][1]=false;
	int x,y,xx,yy;
	while (!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for (int k=0;k<=3;k++)
		{
			xx=x+dx[k];
			yy=y+dy[k];
			if (xx>0 && xx<=n && yy>0 && yy<=n && a[xx][yy]==0 && d[xx][yy]==true)
			{
				if (xx==n && yy==n) return true;
				d[xx][yy]=false;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
	return false;
}
void process()
{
	res=qhd();
	if (res) cout<<res;
	else
	{
		if (checkgamelie()) cout<<"THE GAME IS A LIE";
		else cout<<"INCONCEIVABLE";
	}
}
int main()
{
	memset(d,true,sizeof(d));
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
