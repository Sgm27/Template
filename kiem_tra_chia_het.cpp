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


int main()
{
//	freopen("thu.inp","r",stdin);
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	if (a%b==0 && a%c==0)
		printf("YES");
	else
		printf("N0");
}

