#include <bits/stdc++.h>
using namespace std;
int n,a[105],b[105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
}
void Swap(int i,int j)
{
	for (int k=i;k<=j;k++) b[k]=1-b[k];
}
void process()
{
	int res=0,cs1,cs2;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			for (int k=1;k<=n;k++) b[k]=a[k];
			Swap(i,j);
			int sum=0;
			for (int k=1;k<=n;k++)
				if (b[k]==1) sum++;
			res=max(res,sum);
		}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
