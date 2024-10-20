#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200005],sum[200005],res[200005],tong[200005];
void input()
{
	cin>>n>>m;
	sum[0]=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		cout<<sum[i]<<" ";
	}
}
void process()
{
	for (int i=1;i<=n;i++)
	{
		tong[i]=0;
		if (i<=m) tong[i]=sum[i];
		else
		{
			tong[i]=sum[i]-sum[i-m];
		}
	}
//	for (int i=1;i<=n;i++) cout<<sum[i]<<" "<<tong[i]<<endl;
	for (int i=1;i<=n;i++)
	{
		ll dem=0;
		for (int j=i;j<=n;j+=m)
		{
			dem++;
			res[j]+=tong[i]*dem;
		}
	}
//	for (int i=1;i<=n;i++) cout<<res[i]<<" ";
}
int main()
{
	freopen("thu.inp","r",stdin);
//	freopen("thu.out","w",stdout);
	input();
	process();
}
