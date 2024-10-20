#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a,int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}
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
	int tc,x,y;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",gcd(x,y));
	}
}

