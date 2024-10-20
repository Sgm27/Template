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
	int t;
	double a,b,c,r;
	scanf("%d",&t);
	if (t==1)
	{
		scanf("%lf",&r);
		double tmp=3.14*r*r;
		ll x=(ll)(tmp*100);
		if ((ll)(tmp*1000)%10>=5) x++;
		if (x%100==0)
		{
			printf("%lld",x/100);
			return 0;
		}
		else
		{
			printf("%lld.%.2lld",x/100,x%100);
			return 0;
		}
 	}
 	if (t==2) 
 	{
 		ll x,y;
 		scanf("%lld %lld",&x,&y);
 		printf("%lld",x*y);
 		return 0;
	}
	if (t==3)
	{
		int check=0;
		scanf("%lf %lf %lf",&a,&b,&c);
		if (a+b>c && b+c>a && c+a>b) check=1;
		if (!check) 
		{
			printf("Nope");
			return 0;
		}
		double tmp=0.25*sqrt((a+b+c)*(a+b-c)*(b+c-a)*(a+c-b));
		ll x=(ll)(tmp*100);
		if ((ll)(tmp*1000)%10>=5) x++;
		if (x%100==0)
		{
			printf("%lld",x/100);
			return 0;
		}
		else
		{
			printf("%lld.%.2lld",x/100,x%100);
			return 0;
		}
	}
}

