#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
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
	while (tc--)
	{
		int n,m,p,a[150][150];
		scanf("%d %d %d",&n,&m,&p);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		for (int i=1;i<=n-1;i++)
			for (int j=i+1;j<=n;j++) 
				if (a[i][p]>a[j][p]) swap(&a[i][p],&a[j][p]);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
}

