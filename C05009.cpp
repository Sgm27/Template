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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int n,a[55][55];
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	int cs1=1,cs2=n;
	for (int i=1;i<=n;i++) swap(&a[i][i],&a[cs1++][cs2--]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
}

