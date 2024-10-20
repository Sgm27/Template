#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];
void rutgon(int a,int b)
{
	int tmp=__gcd(a,b);
	if (tmp>0) cout<<a/tmp<<"/"<<b/tmp;
	else 
	{
		if (a<0) 
		{
			cout<<-a/tmp<<"/"<<-b/tmp;
			return;
		}
		if (b<0) 
		{
			cout<<a/tmp<<"/"<<b/tmp;
			return;
		}
	}
} 
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n+1;i++) cin>>a[i];
	for (int i=1;i<=m+1;i++) cin>>b[i];
} 
void process()
{
	if (n>m) 
	{
		if (a[1]>0 && b[1]>0) 
		{
			cout<<"Infinity";
			return;
		}
		else 
		{
			cout<<"-Infinity";
			return;
		}
	} 
	if (n<m)
	{
		cout<<"0/1";
		return;
	}
	rutgon(a[1],b[1]);
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
