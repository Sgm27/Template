#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
//	freopen("thu.inp","r",stdin);
	double h,r;
	scanf("%lf %lf",&h,&r);
	printf("%.3lf",round(1.0/3*3.14*r*r*h*1000)/1000);
}

