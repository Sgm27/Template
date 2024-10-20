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
	int l=64+n-1;
	for (int i=n;i>=1;i--)
	{
		for (int j=l;j<=l+i-1;j++) printf("%c",j);
		l--;
		printf("\n");
	}
}

