#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll tt,a[10005],s[10005];
bool cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
void process(ll n)
{
	s[0]=0;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll sum=s[n];
	vector<ll> v;
	for (int i=1;i<=sqrt(sum);i++)
		if (sum%i==0)
		{
			v.push_back(i);
			v.push_back(sum/i);
		}
	if (cp(n)) v.pop_back();
	sort(v.begin(),v.end());
	for (ll x : v)
	{
		int cs=0;
		for (int i=cs+1;i<=n;i++)
		{
			if (s[i]-s[cs]>x) break;
			if (s[i]-s[cs]==x) cs=i;
		}
		if (cs==n) 
		{
			cout<<tt<<" "<<x<<endl;
			return;
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>tt;
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		process(n);
	}
}
