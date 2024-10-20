#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[805],b[805],cnt=0;
void process(ll a[],ll b[],ll n)
{
	cout<<"Case #"<<cnt<<": ";
	sort(a+1,a+1+n);
	sort(b+1,b+1+n,greater<ll>());
	long long res=0;
	for (ll i=1;i<=n;i++) res+=a[i]*b[i];
	cout<<res<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	ll tc; cin>>tc;
	while (tc--)
	{
		cnt++;
		ll n; cin>>n;
		for (ll i=1;i<=n;i++) cin>>a[i];
		for (ll i=1;i<=n;i++) cin>>b[i];
		process(a,b,n);
	}
}
