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
	double a,b,c,delta;
	scanf("%lf %lf %lf",&a,&b,&c);
	delta=b*b-4*a*c;
	if (delta<0) 
	{
		printf("NO\n");
		return 0;
	}
	if (delta==0) 
	{
		printf("%.2lf",-b/2*a);
		return 0;
	}
	printf("%.2lf %.2lf",(-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
}

