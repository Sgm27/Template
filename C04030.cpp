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
int cmp1(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int cmp2(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *y-*x;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc,stt=0;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,a[105],b[105],l1=0,l2=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		qsort(a+1,n,sizeof(int),cmp1);
		qsort(b+1,n,sizeof(int),cmp2);
		printf("Test %d:\n",++stt);
		for (int i=1;i<=2*n;i++)
			if (i%2) printf("%d ",a[++l1]);
			else printf("%d ",b[++l2]);
		printf("\n");
	}
}

