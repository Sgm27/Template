#include <iostream>
using namespace std;
int n,a[20][20],res=1e9,sum=0,x[20],cmin=1e9+5;
bool d[20];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) d[i]=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			if (a[i][j]) cmin=min(cmin,a[i][j]);
		}
}
void Try(int i)
{
	for (int j=2;j<=n;j++)
		if (d[j])
		{
			d[j]=false;
			x[i]=j;
			sum+=a[x[i-1]][j];
			if (i==n) 
			{
				res=min(res,sum+a[x[n]][1]);
			}
			else 
				if (sum+cmin*(n-i+1)<res) Try(i+1);
			d[j]=true;
			sum-=a[x[i-1]][j];
		}
}
int main()
{
	// freopen("thu.inp","r",stdin);
	input();
	d[1]=false;
	x[1]=1;
	Try(2);
	cout<<res;
}
