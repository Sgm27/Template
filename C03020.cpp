#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,l,r;

ll max(ll a,ll b)
{
	if (a>b) return a;
	return b;
}
ll min(ll a,ll b)
{
	if (a>b) return b;
	return a;
}
int check_tn(ll k)
{
	int i=1,a[15],nmax=0;
	while (k)
	{
		a[++nmax]=k%10;
		k/=10;
	}
	for (int i=1;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}
int check_digit(ll k)
{
	int sum=0,check=0;
	while (k)
	{
		sum+=k%10;
		if (k%10==6) check=1;
		k/=10;
	}
	if (!check) return 0;
	if (sum%10!=8) return 0;
	return 1;
}
int check(ll k)
{
	if (check_tn(k) && check_digit(k)) return 1;
	return 0;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%lld %lld",&l,&r);
	ll cnt=0;
	if (l>r) 
	{
		ll tmp=l;
		l=r;
		r=tmp;
	}
	for (ll i=l;i<=r;i++) 
		if (check(i)) printf("%lld ",i);
}

