#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,a[1000005],s[1000005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	sort(a+1,a+1+n,greater<ll>());
	s[0]=0;
	ll tmp;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll res=-1;
	for (int i=1;i<=n;i++)
	{
		tmp=(s[i]-k)/i;
		if (tmp>res && tmp<a[i]) res=tmp;
	}
	cout<<res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
