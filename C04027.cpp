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
	freopen("thu.inp","r",stdin);
	int n,a[105],stt=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n-1;i++)
	{
		int Min=i;
		for (int j=i+1;j<=n;j++) 
			if (a[j]<a[Min]) Min=j;
	//	if (Min!=i) 
		{
			swap(&a[i],&a[Min]);
			stt++;
			printf("Buoc %d: ",stt);
	 		for (int k=1;k<=n;k++) printf("%d ",a[k]);
			printf("\n");
		}
	}
}

