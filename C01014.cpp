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
	if (a==0 && b==0) 
		printf("Vo so nghiem");
	if (a==0 && b!=0)
		printf("Vo nghiem");
	if (a!=0) printf("%.2lf",-b/a);
}

