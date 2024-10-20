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
	int n,m,l=0,r=-1;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		if (i<=m)
		{
			l++;
			r++;
			for (int j=l;j<=m;j++) printf("%d",j);
			for (int j=r;j>=1;j--) printf("%d",j);
			printf("\n");
		}
		else
		{
			printf("%d",i);
			for (int j=m-1;j>=1;j--) printf("%d",j);
			printf("\n");
		}
	}
}

