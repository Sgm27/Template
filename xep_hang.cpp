#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,res[200005],st;
int ke1[1000005],ke2[1000005],a[1000005],b[1000005];
void input()
{
	for (int i=0;i<=1000005;i++) ke1[i]=ke2[i]=-1;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		int x,y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		ke1[x]=y;
		ke2[y]=x;
	}
	for (int i=1;i<=n;i++)
		if (ke1[a[i]] && ke2[a[i]]==-1) st=a[i];
}
void process1()
{
	// xu ly tu dau
	int u,i=2;
	u=0;
	while (ke1[u]!=-1) 
	{
		res[i]=ke1[u];
		u=ke1[u];
		i+=2;
	}
	u=0;
	// xu ly tu cuoi
	i=n-1;
	while (ke2[u])
	{
		res[i]=ke2[u];
		u=ke2[u];
		i-=2;
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}
void process2()
{
	// xu ly tu dau
	int u,i=2;
	u=0;
	while (ke1[u]) 
	{
		res[i]=ke1[u];
		u=ke1[u];
		i+=2;
	}
	u=st;
	i=3;
	res[1]=st;
	while (ke1[u]!=-1)
	{
		res[i]=ke1[u];
		u=ke1[u];
		i+=2;
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}
int main()
{
	freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	if (n%2==0) process1();
	else process2();
}

