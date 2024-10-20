#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
	double a,b;
	scanf("%lf %lf",&a,&b);
	if (b==0) 
	{
		printf("0");
		return 0;
	}
	printf("%.0lf %.0lf %.0lf %.2lf",a+b,a-b,a*b,a/b);
	int x=(int)a;
	int y=(int)b;
	printf(" %d",x%y);
}

