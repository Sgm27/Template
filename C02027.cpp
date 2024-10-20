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
	int n,a[150][150],cs=96,tmp=1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		cs+=i;
		if (i%2==0)
			for (int k=1;k<=i;k++) a[i][k]=cs-k+1;
		else 
			for (int k=1;k<=i;k++) a[i][k]=cs-i+k;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (a[i][j]) printf("%c ",(char)(a[i][j]));
		printf("\n");
	}
}

