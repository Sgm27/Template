#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
int min(int a,int b)
{
	if (a>b) return b;
	return a;
}
int check(ll n)
{
	int a[105],nmax=0;
	while (n)
	{
		a[++nmax]=n%10;
		n/=10;
	}
	if (a[1]!=2*a[nmax] && a[nmax]!=2*a[1]) return 0;
	for (int i=2;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll n;
		scanf("%lld",&n);
		if (check(n)) printf("YES\n");
		else printf("NO\n");
	}
}

