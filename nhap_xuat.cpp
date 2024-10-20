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
	int a;
	long long b;
	char c;
	float d;
	double e;
	scanf("%d %lld %c %f %lf",&a,&b,&c,&d,&e);
	printf("%d\n%lld\n%c\n%.3f\n%.7lf",a,b,c,d,e);
}

