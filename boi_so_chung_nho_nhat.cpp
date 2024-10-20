#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll a,b;
void input()
{
	cin>>a>>b;
}
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
void process()
{
	ll t=abs(a-b),tmp,n_tmp,X=min(a,b),Min=INT_MAX,res=INT_MAX,tt;
	if (t==0) 
	{
		cout<<1;
		return;
	}
	for (int i=1;i<=sqrt(t);i++)
		if (t%i==0)
	{
		n_tmp=(X/i+1)*i-X;
		tt=((a+n_tmp)*(b+n_tmp)/gcd(a+n_tmp,b+n_tmp));
		if (tt<Min)	
		{
			Min=tt;
			res=n_tmp;
		}
		else 
		if (Min==tt && n_tmp<res) res=n_tmp;
		ll j=t/i;
		n_tmp=(X/j+1)*j-X;
		tt=((a+n_tmp)*(b+n_tmp)/gcd(a+n_tmp,b+n_tmp));
		if (tt<Min)	
		{
			Min=tt;
			res=n_tmp;
		}
		else 
		if (Min==tt && n_tmp<res) res=n_tmp;	
 	}
 	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
