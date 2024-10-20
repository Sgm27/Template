#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
string a[1000005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
}
void process()
{
	ll x=sqrt(2*k)-1;
	while ((x*(x+1))/2<k) x++;
	cout<<a[k-x*(x-1)/2];
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
