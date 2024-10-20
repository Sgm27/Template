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
	//freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		if (i>=3 && i!=n) 
		{
			printf("*");
			for (int j=2;j<=i-1;j++) printf(".");
			printf("*");
		}
		else
			for (int j=1;j<=i;j++) printf("*");
		printf("\n");
	}
}


