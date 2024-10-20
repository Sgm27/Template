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
	double f,c;
	scanf("%lf",&f);
	c=(f-32)/1.8;
	int am=0;
	if (c<0) am=1;
	if (am) c=-c;
	ll tmp=(int)(c*100);
	if (am) printf("-");
	if ((int)(c*1000)%10>=5) tmp++;
	int x=tmp%100;
	if (x==0)
	{
		printf("%d",tmp/100);
		return 0;
	}
	if (x<10)
	{
		printf("%d.%.2d",tmp/100,x);
		return 0;
	}
	if (x>=10)
	{
		if (x%10==0) 
		{
			x/=10;
			printf("%d.%d",tmp/100,x);
			return 0;
		}
		printf("%d.%d",tmp/100,x);
	}
}

