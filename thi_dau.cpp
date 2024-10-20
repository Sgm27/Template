#include <bits/stdc++.h>
using namespace std;
void process()
{
	int kk;
	cin>>kk;
	string kq;
	int sbmax=-1;
	int dmin=INT_MAX;
	string tmp;
	int x,y,sum,sb;
	for (int i=1;i<=4;i++)
	{
		sum=0; sb=0;
		cin>>tmp;
		for (int j=1;j<=4;j++)
		{
			cin>>x>>y;
			if (y!=0) 
			{
				sum+=((x-1)*20+y);
				sb++;
			}
			if (sb>sbmax)
			{
				sbmax=sb;
				kq=tmp;
				dmin=sum;
			}
			else 
			if (sb==sbmax && sum<dmin)
			{
				kq=tmp;
				dmin=sum;
			}
		}
	}
	cout<<kq<<" "<<sbmax<<" "<<dmin;
}
int main()
{
	freopen("thu.inp","r",stdin);
	process();
}
