#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double xa,xb,xc,ya,yb,yc,a,b,c,res;
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
int check(double x,double y,double z)
{
	if (x+y>z && x+z>y && y+z>x) return 1;
	return 0;	
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc);
		a=sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
		b=sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
		c=sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
		if (check(a,b,c))
		{
			res=a+b+c;
			res=round(res*1000)/1000;
			printf("%.3lf\n",res);
		}
		else printf("INVALID\n");
	}
}

