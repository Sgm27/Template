#include <bits/stdc++.h>
using namespace std;
int n,k,d[100005],dd[100005],a[100005],b[100005],kq[100005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	a[n+1]=-1;
	int i=1,dem=0;
	while (i<=n)
	{
		if (a[i]!=a[i+1]) 
		{
			dem++;
			b[dem]=a[i];
		}
		i++;
	}
	n=dem; b[0]=-1; b[n]=-1;
	for (int i=1;i<=n;i++) 
		{
			d[b[i]]++;
			if (b[i-1]==b[i+1]) dd[b[i]]++;
		}
	int res=INT_MAX;
	for (int i=1;i<=n;i++)
		{
			kq[b[i]]=n-d[b[i]]-dd[b[i]];
			res=min(res,kq[b[i]]);
		}
	for (int i=1;i<=k;i++) 
		if (kq[i]==res) 
		{
			cout<<i;
			return;
		}
}
int main()
{
	memset(d,0,sizeof(d));
	memset(dd,0,sizeof(dd));
	freopen("thu.inp","r",stdin);
	input();
	process();
}
