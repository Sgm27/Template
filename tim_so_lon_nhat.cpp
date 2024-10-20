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
	int a,b,c,d,Max;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	Max=a;
	if (b>Max) Max=b;
	if (c>Max) Max=c;
	if (d>Max) Max=d;
	printf("%d",Max);
}

