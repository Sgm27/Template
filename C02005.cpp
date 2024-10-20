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
//	freopen("thu.inp","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i-1;j++) printf("~");
		for (int j=1;j<=m;j++) printf("*");
		printf("\n");
	}
}

