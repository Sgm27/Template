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
	double a,b,c;
	scanf("%lf %lf",&a,&b);
	c=a/b;
	c-=(int)(c);
	printf("%d",(int)(c*10)%10+(int)(c*100)%10+(int)(c*1000)%10+(int)(c*10000)%10+(int)(c*100000)%10);
}

