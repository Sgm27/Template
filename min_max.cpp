#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int m,s,a[105];
void input()
{
	cin>>m>>s;	
}
void process()
{
	if (m==1 && s==0) 
	{
		cout<<"0 0";
		return;
	}
	if (s>9*m || s==0)
	{
		cout<<"-1 -1";
		return;
	}
	int i=1,tmp=s; 
	while (i<=m)
	{
		if (tmp>9) 
		{
			a[i]=9;
			tmp-=9;
		}
		else 
		{
			if (i==m) a[i]=tmp;
			else 
			{
				a[i]=tmp-1;
				tmp=1;
				while (i!=m) 
				{
					i++;
					a[i]=0;
				}
				a[i]=1;
			}
		}
		i++;
	}
	for (int i=m;i>=1;i--) cout<<a[i];
	cout<<" ";
	//tim_so_lon
	tmp=s; i=1;
	while (i<=m)
	{
		if (tmp>=9) 
		{
			cout<<9; tmp-=9;
		}
		else{
				cout<<tmp;
				break;
			}
		i++;
	}
	for (int j=i+1;j<=m;j++) cout<<0;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
