#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,l;
double a[100005];
void input()
{
	cin>>n>>l;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	sort(a+1,a+1+n);
	double res=-1;
	res=max(a[1],l-a[n]);
	for (int i=1;i<=n-1;i++)
	{
		res=max(res,(double)((a[i+1]-a[i])*0.5));
	}
	cout<<fixed<<setprecision(10)<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}

