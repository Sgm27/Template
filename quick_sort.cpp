#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n,a[10005];
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
void sort(int l,int r)
{
	int i=l,j=r,g=a[(int)((i+j)/2)];
	while (i<=j)
	{
		while (a[i]<g) i++;
		while (a[j]>g) j--;
		if (i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r); 
}
int main()
{
	freopen("quick_sort.inp","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(1,n);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}

