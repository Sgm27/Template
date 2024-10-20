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
	long long a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	long long Max=a;
	if (b>Max) Max=b;
	if (c>Max) Max=c;
	if (d>Max) Max=d;
	printf("%lld",Max);
}

