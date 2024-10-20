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
	int n,a[15][15],cs=0,tmp=0;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		tmp++;
		for (int k=tmp;k<=n;k++) a[k][i]=++cs;
	}
	for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) 
			if (a[i][j]) printf("%d ",a[i][j]);
			printf("\n");
		}
}

