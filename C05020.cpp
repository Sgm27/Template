#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long f[90];
void init()
{
	f[0]=0; 
	f[1]=1;
	for (int i=2;i<=90;i++) f[i]=f[i-1]+f[i-2];
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int tc;
	//scanf("%d",&tc);
//	for (int k=1;k<=tc;k++)
//	{
//		printf("Test %d:\n",k);
		long long a[100][100],i,j,hang,cot,n,d,gt,x,y;
		scanf("%lld",&n);
		gt=0;
		hang=n-1; cot=n-1;d=0;
		while(d<=n/2)
		{
			for (i=d;i<=cot;i++) a[d][i]=f[gt++];
			for (i=d+1;i<=hang;i++) a[i][cot]=f[gt++];
			for (i=cot-1;i>=d;i--) a[hang][i]=f[gt++];
			for (i=hang-1;i>d;i--) a[i][d]=f[gt++];
			d++;hang--;cot--;
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++) printf("%lld ",a[i][j]);
			printf("\n");
		}
//	}
} 
