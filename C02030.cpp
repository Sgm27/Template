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
	int n;
	scanf("%d",&n);
	int r=66;
	printf("@\n");
	for (int i=1;i<=n-1;i++)
	{
		printf("@");
		for (int j=66;j<=r;j+=2) printf("%c",(char)j);
		for (int j=r-2;j>=66;j-=2) printf("%c",(char)j);
		r+=2;
		printf("@\n");
	}
}

