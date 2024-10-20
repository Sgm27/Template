#include <bits/stdc++.h>
using namespace std;
int n,x[100000],sum;
void nhap()
{
	cin>>n;
}
void in(int num)
{
	for (int i=1;i<=num;i++) cout<<x[i]<<" ";
	cout<<endl;
}
void thu(int i)
{
	for (int j=x[i-1];j<=n;j++)
		if (sum+j<=n)
	{
		x[i]=j;
		sum+=x[i];
		if (sum==n) in(i);
		else thu(i+1);
		sum-=x[i];
	}
}
int main()
{
	freopen("son.inp","r",stdin);
	freopen("son.out","w",stdout);
	nhap();
	x[0]=1; sum=0;
	thu(1);
}
