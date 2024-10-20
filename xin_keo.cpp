#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
int a[100005],b[100005],n,m;
void nhap()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
}
void xuly()
{
	ll t1=1;
	for (int i=1;i<=n;i++) 
		if (a[i]==2) t1=(t1*b[i])%MOD;
	ll t2=0;
	for (int i=1;i<=n;i++)	
	{
		if (a[i]==1) t2=(t2+b[i])%MOD;
		else t2=(t2*b[i])%MOD;
	}
	ll res=1;
	while (m>=0)
	{
		res=(t1*res+t2)%MOD; 
		m--;
	}
	cout<<res;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	nhap();
	xuly();
}
