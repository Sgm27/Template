#include <bits/stdc++.h>
using namespace std;
int n,k,bd,kt;
int d[100005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if (x=='#') d[i]=-1;
		if (x=='G') bd=i;
		if (x=='T') kt=i;
	}
}
void process()
{
	int i=1;
	int dd;
	if (bd<kt) dd=1;
	else dd=2;
	while (1)
	{
		if (bd==kt)
		{
			cout<<"YES";
			return;
		}
		if (dd==1) bd+=k;
		else bd-=k;
		if (d[bd]==-1)
		{
			cout<<"NO";
			return;
		}
		if (dd==1 && bd>kt) 
		{
			cout<<"NO";
			return;
		}
		if (dd==2 && bd<kt)
		{
			cout<<"NO";
			return;
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
