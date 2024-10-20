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
	int n,r=2;
	scanf("%d",&n);
	for (int k=1;k<=n;k++)
	{
		for (int i=2;i<=r;i+=2) printf("%d",i);
		for (int i=r-2;i>=2;i-=2) printf("%d",i);
		r+=2;
		printf("\n");
	}
}

