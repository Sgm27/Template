#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
//	freopen("thu.inp","r",stdin);
	int m,n;
	int a[100][100];
	scanf("%d %d",&n,&m);
	for (int k=0;k<n;k++)
	{
		int i,j,hang,cot,n,d,gt=1,x,y;
		hang=n-1; cot=n-1;d=0;
		while(d<=n/2)
		{
			for (i=d;i<=cot;i++) a[d][i]=gt++;
			for (i=d+1;i<=hang;i++) a[i][cot]=gt++;
			for (i=cot-1;i>=d;i--) a[hang][i]=gt++;
			for (i=hang-1;i>d;i--) a[i][d]=gt++;
			d++;hang--;cot--;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
} 
