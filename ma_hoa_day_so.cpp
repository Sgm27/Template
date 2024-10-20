#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
struct mang{
	ll gt,cs,sl;
};
mang a[1005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i].gt;
		a[i].cs=i;
	}
}
bool cmp(mang x,mang y)
{
	if (x.gt!=y.gt) return x.gt<y.gt;
	else return x.cs<y.cs;
}
bool compa(mang x,mang y)
{
	if (x.sl!=y.sl) return x.sl>y.sl;
	else return x.cs<y.cs;
}
void process()
{
	a[n+1].gt=-1;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n-1;i++)
		if (a[i].gt==a[i+1].gt) a[i+1].cs=a[i].cs;
	int dem=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i].gt!=a[i+1].gt) 
		{
			a[i].sl=dem;
			dem=1;
		}
		else dem++;
	}
	sort(a+1,a+1+n,compa);
	for (int i=1;i<=n;i++)
		while (a[i].sl!=0)
		{
			cout<<a[i].gt<<" ";
			a[i].sl--;
		}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
