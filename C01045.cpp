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
	int n,a[50],k=0;
	scanf("%d",&n);
	while (n)
	{
		int tmp=n%10;
		a[++k]=tmp;
		n/=10;
	}
	printf("%d %d",a[k],a[1]);
}

