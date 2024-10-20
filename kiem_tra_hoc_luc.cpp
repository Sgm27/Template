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
	double a,b,c,tb;
	scanf("%lf %lf %lf",&a,&b,&c);
	tb=(a+b+c)/3;
	if (tb<5) printf("yeu");
	else
	if (tb<6.5) printf("trung binh");
	else
	if (tb<8) printf("kha");
	else
		printf("gioi");
}

