#include <bits/stdc++.h>
using namespace std;
const int inf=1e7;
bool dd[1005];
int n,m,h,d[1005],a[1005];
vector<int> ke[1005];
void input()
{
	cin>>n>>m>>h;
	for (int i=0;i<n;i++) d[i]=inf;
	for (int i=1;i<=m;i++) 
	{
		cin>>a[i];
		d[a[i]]=0;
	}
	for (int i=1;i<=h;i++)
	{
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void bfs(int i)
{
	queue<int> Q;
	Q.push(i);
	dd[i]=false;
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for (int k : ke[x])
			if (dd[k])
			{
				if (d[k]==0) continue;
				dd[k]=false;
				d[k]=min(d[x]+1,d[k]);
				Q.push(k);	
			}
	}
}
void process()
{
	for (int i=1;i<=m;i++)	
	{
		for (int j=0;j<n;j++) dd[j]=true;
		bfs(a[i]);
	}
	int res=-1;
	for (int i=0;i<n;i++) 
	{
		res=max(res,d[i]);
	}
	for (int i=0;i<n;i++)
		if (d[i]==res)
		{
			cout<<i;
			return;
		}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
