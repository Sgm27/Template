#include <bits/stdc++.h>
using namespace std;
int x,y,prime[10005],dem[10005];
vector<int> nt,ke[10005];
bool d[10005];
void sang()
{
	const int N=9999;
	for (int i=0;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
		 	for (int j=i*i;j<=N;j+=i) prime[j]=0;
	for (int i=1000;i<=N;i++) 
		if (prime[i]) nt.push_back(i);
}
bool check(int a,int b)
{
	int cnt=0;
	while (a)
	{
		if (a%10!=b%10) cnt++;
		a/=10; b/=10;
	}
	return cnt==1;
}
void init()
{
	for (int i=0;i<nt.size()-1;i++)
		for (int j=i+1;j<nt.size();j++)
			if (check(nt[i],nt[j]))
			{
				ke[nt[i]].push_back(nt[j]);
				ke[nt[j]].push_back(nt[i]);
			}
}
void bfs(int dau,int cuoi)
{
	memset(d,true,sizeof(d));
	memset(dem,0,sizeof(dem));
	dem[dau]=0;
	queue<int> q;
	q.push(dau);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		d[u]=false;
		if (u==cuoi) 
		{
			cout<<dem[cuoi]<<endl;
			return;
		}
		for (int i=0;i<ke[u].size();i++)
		{
			int v=ke[u][i];
			if (d[v])
			{
				d[v]=false;
				dem[v]=dem[u]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	sang();
	init();
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>x>>y;
		bfs(x,y);
	}
}
