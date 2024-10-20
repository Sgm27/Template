#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,chan,le;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>n>>k;
	if (n%2==0) 
	{
		chan=n/2; le=n/2;
	}
	else 
	{
		chan=(ll)(n/2); le=n-chan;
	}
	if (k<=le) cout<<(ll)(1+(k-1)*2);
	else cout<<(ll)(2+(k-le-1)*2);
}
