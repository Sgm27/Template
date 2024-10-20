#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,dem=0,so=0;
bool d[105][105],check[105];
map<int,int> mp;
vector<int> res;
void tim(int i)
{
	res.push_back(i);
	for (int j=1;j<=n;j++)
	{
		if (d[i][j] && check[j])
			{
				check[j]=false;
				if (j==v) 
					{
						for (int x : res) mp[x]++;
						//for (int x : res) cout<<x<<" ";
					//	cout<<endl;
						so++;
						res.pop_back();
					}
				else tim(j);
				check[j]=true;
			}
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		so=0;
		memset(d,false,sizeof(d));
		memset(check,true,sizeof(check));
		cin>>n>>m>>u>>v;
		for (int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
		//	if (x==v) continue;
			d[x][y]=true;
		}
		check[u]=false;
		tim(u);
		int cnt=0;
		for (pair<int,int> x : mp) 
			if (x.second==so) 
			{
				cnt++;
				//cout<<x.first<<" ";
			}
		cout<<cnt-1<<endl;
		mp.clear();
		res.clear();
	}
}

