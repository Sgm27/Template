#include <iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll a[100005],k,n,cs_max[100005];
struct mang{
	ll cs,gt;
};
mang sum[100005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]-=k;
	}
}
bool cmp(mang a,mang b)
{
	if (a.gt!=b.gt) return a.gt<b.gt;
	else return a.cs<b.cs;
}
void process()
{
	bool check=true;
	for (int i=1;i<=n;i++)
		if (a[i]<0) 
		{
			check=false;
			break;
		}
	if (check)
	{
		cout<<n;
		return;
	}
	ll res=0;
	sum[0].gt=0;
	sum[0].cs=0;
	for (int i=1;i<=n;i++)
	{
		sum[i].gt=sum[i-1].gt+a[i];
		sum[i].cs=i;
	}
	sort(sum,sum+1+n,cmp);
	cs_max[n]=sum[n].cs;
	for (int i=n-1;i>=0;i--)
		cs_max[i]=max(cs_max[i+1],sum[i].cs);
	for (int i=0;i<=n-1;i++)
		res=max(res,cs_max[i+1]-sum[i].cs);
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
