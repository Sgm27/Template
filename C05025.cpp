#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n,m,a[1005][1005],stt=0;
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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void process()
{
	printf("Test %d:\n",stt);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int x=i;x<=n;x++)
				for (int y=j;y<=m;y++)
					if (a[i][j]>a[x][y]) swap(&a[i][j],&a[x][y]);
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=m;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		stt++;
		process();
	}
}

