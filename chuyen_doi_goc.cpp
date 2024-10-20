#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll lcm(ll a,ll b)
{
	if (b==0) return a;
	else return lcm(b,a%b);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll x; cin>>x;
		x%=360;
		ll tmp=lcm(x,180);
		ll a=x/tmp,b=180/tmp;
		if (a>=2*b || a==0) 
		{
			cout<<"0$"<<endl;
		}
		else 
		if (a==1 && b!=1) cout<<"$/"<<b<<endl;
		else
		if (a==1 && b==1) cout<<"$"<<endl;
		else cout<<a<<"$/"<<b<<endl;
	}
}
