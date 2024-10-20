#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db=long double;
const db eps=1e-14;
ll a,b,x;
void input()
{
	cin>>a>>b>>x;
}
db f(ll k)
{
	return (db)((db)(a*pow(k*1.0,1/3.0))+(db)(b*pow(k*1.0,1/2.0)));
}
void process()
{
	ll l=0,r=x*x+1;
	while (r-l>1)
	{
		ll mid=(l+r)/2;
		if (f(mid)+eps>=(db)(x)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	process();
}

