#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool check[10000005];
void sang()
{
	ll n=10000000;
	for (int i=2;i<=n;i++) check[i]=true;
	for (int i=2;i<=sqrt(n);i++)
		if (check[i])
			for (int j=i*i;j<=10000000;j+=i) check[j]=false;
}
bool ok(string s)
{
	int Max=-1;
	for (int i=0;i<s.length();i++) Max=max(Max,s[i]-'0');
	if (Max==s[s.length()-1]-'0') return true;
	return false;
}
void process(ll n)
{
	ll cnt=0;
	for (int i=2;i<=n;i++)
		if (check[i])
		if (ok(to_string(i))) 
		{
			cout<<i<<" ";
			cnt++;
		}
	cout<<endl<<cnt;
}
int main()
{
	freopen("thu.inp","r",stdin);
	sang();
	ll n; cin>>n;
	process(n);
}
