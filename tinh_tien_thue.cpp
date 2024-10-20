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
	int n,tmp;
	scanf("%d",&n);
	if (n>=20) 
	{
		tmp=5*n;
		if (tmp%10==0) tmp/=10;
		if (tmp%10==0) tmp/=10;
		if (tmp>100)
			printf("%d.%d",tmp/100,tmp%100);
		else
		if (tmp>10)
			printf("%d.%d",tmp/10,tmp%10);
		else 
			printf("%d",tmp);
	}
	else 
	{
		if (n>=10) tmp=3*n;
		else tmp=1*n;
		if (tmp<10)
			printf("0.%.2d",tmp);
		else
		{
			if (tmp%10==0) tmp/=10;
			printf("0.%d",tmp);
		}
	}
}

