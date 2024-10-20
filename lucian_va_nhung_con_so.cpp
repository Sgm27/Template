#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5]={0},b[5]={0};
void input()
{
	cin>>n>>m;
}
void process()
{
	for (int i=1;i<=n;i++) a[i%5]++;
	for (int i=1;i<=m;i++) b[i%5]++;
	ll cnt=a[0]*b[0];
	ll j=4;
	for (ll i=1;i<=4;i++)
	{
		cnt+=a[i]*b[j];
		j--;
	}
	cout<<cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
