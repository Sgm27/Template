#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
		{
			ll x;
			cin>>x;
			cout<<x-n*m<<" ";
		}
}
