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
	if (n%2) return 0;
	int dc=0,dl=0;
	while (n)
	{
		int tmp=n%10;
		if (tmp%2) dl++; else dc++;
		n/=10;
	}
	if (dc>dl) return 1;
	return 0;
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

