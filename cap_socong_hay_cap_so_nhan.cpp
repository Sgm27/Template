#include <bits/stdc++.h>
using namespace std;
int a[5];
bool check_sn()
{
	int tmp;
	if (a[2]%a[1]!=0) return false;
	else tmp=a[2]/a[1];
	for (int i=2;i<=3;i++)
		if (a[i+1]%a[i]!=0) return false;
		else 
		{
			if (a[i+1]/a[i]!=tmp) return false;
		}
	return true;
}
bool check_sc()
{
	int tmp=a[2]-a[1];
	for (int i=1;i<=3;i++)
		if (a[i+1]-a[i]!=tmp) return false;
	return true;
}
void process()
{
	a[5]=10000;
	a[0]=1;
	int cnt;
	for (int i=1;i<=4;i++) 
		if (a[i]==-1) cnt=i;
	for (int i=a[cnt-1];i<=a[cnt+1];i++)
	{
		a[cnt]=i;
		if (check_sn() || check_sc()) 
		{
			cout<<i<<endl;
			return;
		}
	}
	cout<<"-1\n";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (cin>>a[1]>>a[2]>>a[3]>>a[4])
	{
		if (a[1]==-1 && a[2]==-1) return 0;
		process();
	}
}
