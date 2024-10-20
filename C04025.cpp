#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
	int n,a[105],d[105];
	memset(d,1,sizeof(d));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]>a[j]) swap(&a[i],&a[j]);
	for (int i=1;i<=n;i++)
		if (a[i]%2==0) 
		{
			printf("%d ",a[i]);
			d[i]=0;
		}
	for (int i=1;i<=n;i++) 
		if (d[i]) printf("%d ",a[i]);
}

