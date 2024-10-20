// chay sai
#include <bits/stdc++.h>
using namespace std;
int n,m,u,dem;
bool ok=false;
bool check[1005],d[1005][1005];
void dfs(int i)
{
	if (ok) return;
	stack<int> S;
	S.push(i);
	cout<<i<<" ";
	check[i]=false;
	while (!S.empty())
	{
		int x=S.top();
		S.pop();
		for (int k=1;k<=n;k++)
		{
			if (check[k] && d[k][x])
			{
				if (k==n) 
				{
					ok=true;
					return;
				}
				check[k]=false;
				dfs(k);
				check[k]=true;
			}
		}
	}
	if (dem==1) 
	{
		cout<<n<<endl;
		dem++;
	}
}
int main()
{
	memset(d,false,sizeof(d));
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		ok=false;
		dem=1;
		memset(check,true,sizeof(check));
		vector<pair<int,int>> v;
		cin>>n>>m>>u;
		for (int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
			d[x][y]=true;
			d[y][x]=true;
		}
		dfs(u);
		for (pair<int,int> k : v) 
		{
			d[k.first][k.second]=false;
			d[k.second][k.first]=false;
		}
	}
}
