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
	int n;
	double sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		double x;
		scanf("%lf",&x);
		sum+=x;
	}
	printf("%.3lf",sum/n);
}

