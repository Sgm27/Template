#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a[105],b[105];

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
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]>a[j]) 
			{
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
			}
	for (int i=2;i<=n;i++) a[i]=max(a[i],a[i-1]+b[i-1]);
	printf("%d",a[n]+b[n]);
}

