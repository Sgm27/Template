#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
int a[maxn][maxn],d[maxn][maxn],n,m,sx,sy,ex,ey;
bool cx[maxn][maxn];
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
void bfs(int i,int j)
{
	queue<int> qx;
	queue<int> qy;
	qx.push(i); qy.push(j);
	while (!qx.empty())
	{
		int x=qx.front();
		int y=qy.front();
		qx.pop(); qy.pop();
		for (int k=0;k<8;k++)
		{
			int xx=x+dx[k];
			int yy=y+dy[k];
			if (xx>0 && xx<=n && yy>0 && yy<=m && cx[xx][yy])	
			{
				cx[xx][yy]=false;
				d[xx][yy]=min(d[xx][yy],d[x][y]+1);
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m>>sx>>sy>>ex>>ey;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
		{
			d[i][j]=1e9;
			cx[i][j]=true;
		}
	d[sx][sy]=0;
	bfs(sx,sy);
	if (d[ex][ey]!=1e9) cout<<d[ex][ey];
	else cout<<"-1";
}

