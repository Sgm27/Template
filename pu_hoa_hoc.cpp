#include <bits/stdc++.h>
using namespace std;
bool d[55],dd[55][55];
using ll=long long;
ll n,m,cnt,res;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) 
		{
			ll x,y;
			cin>>x>>y;
			dd[x][y]=true;
			dd[y][x]=true;
		}
}
void dfs(ll i)
{
	stack<int> S;
	S.push(i);
	d[i]=false;
	while (!S.empty())
	{
		int x=S.top();
		S.pop();
		for (int j=1;j<=n;j++) 
			if (d[j] && dd[j][x])
			{
				S.push(j);
				d[j]=false;
				cnt++;
			}
	}
}
void process()
{
	res=1;
	for (int i=1;i<=n;i++)
		if (d[i]) 
		{
			cnt=0;
			dfs(i);
			res*=pow(2,cnt);
		}
	cout<<res;
}
int main()
{
	memset(d,true,sizeof(d));
	memset(dd,false,sizeof(dd));
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
