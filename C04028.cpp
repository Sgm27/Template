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
int cmp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y; 
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int n,a[105];
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		qsort(a+1,i,sizeof(int),cmp);
		printf("Buoc %d: ",i-1);
		for (int j=1;j<=i;j++) printf("%d ",a[j]);
		printf("\n");
	}
}

