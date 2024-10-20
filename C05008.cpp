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
	int tc;
	scanf("%d",&tc);
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d:\n",stt);
		int n,m,a[15][15],cs1,cs2;
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		int Max=-1;
		for (int i=1;i<=n;i++)
		{
			int sum=0;
			for (int j=1;j<=m;j++) sum+=a[i][j];
			if (sum>Max)
			{
				Max=sum;
				cs1=i;
			}
		}
		for (int i=1;i<=m;i++) a[cs1][i]=-1;
		Max=-1;
		for (int i=1;i<=m;i++)
		{
			int sum=0;
			for (int j=1;j<=n;j++) sum+=a[j][i];
			if (sum>Max)
			{
				Max=sum;
				cs2=i;
			}
		}
		for (int i=1;i<=n;i++) a[i][cs2]=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) 
				if(a[i][j]!=-1) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
}

