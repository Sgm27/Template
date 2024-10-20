#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[100005],s[100005],sum;
void nhap()
{
	s[0]=0;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i]; 
}
void xuly()
{
	sum=0;
	for (int i=1;i<=n;i++)
		sum+=a[i]*(s[n]-s[i]);
	cout<<sum;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	xuly();
}

