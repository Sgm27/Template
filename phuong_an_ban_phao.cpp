#include <bits/stdc++.h>
using namespace std;
int n,a[105][105],tmp[105];
bool dd[105][105],d[105];
void dfs(int i)
{
	stack<int> S;
	S.push(i);
	d[i]=false;
	int x;
	while (!S.empty())
	{
		x=S.top();
		S.pop();
		for (int j=1;j<=n;j++) 
			if (dd[x][j] && d[j]) 
			{
				S.push(j);
				d[j]=false;
			}
	}
}
void process()
{
	int mc,res,dem,Max=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		memset(d,true,sizeof(d));
		mc=i; dem=0;
		for (int j=1;j<=n;j++) 
			if (dd[j][mc])
			{
				dem++;
				tmp[dem]=j;
				dd[j][mc]=false;
				dd[mc][j]=false;
			}
		d[mc]=false;
		int cnt=0;
		for (int j=1;j<=n;j++)
			if (d[j])
			{
				cnt++;
				dfs(j);
			}
		if (cnt>Max)
		{
			Max=cnt;
			res=mc;
		}
		d[mc]=true;
		for (int j=1;j<=dem;j++)
		{
			dd[tmp[j]][mc]=true;
			dd[mc][tmp[j]]=true;
		}
	}
	if (Max!=1) cout<<res<<endl; else cout<<"0"<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		memset(dd,false,sizeof(dd));
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				int x; cin>>x;
				if (x==1) dd[i][j]=true;
			}
		process();
	}
}
