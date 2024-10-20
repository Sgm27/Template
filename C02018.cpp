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
	//freopen("thu.inp","r",stdin);
	int n,r=1;
	scanf("%d",&n);
	int tmp=n;
	for (int i=1;i<=n;i++)
	{
		tmp--;
		for (int k=1;k<=tmp;k++) printf("~");
		for (int k=1;k<=r;k+=2) printf("%d",k);
		for (int k=r-2;k>=1;k-=2) printf("%d",k);
		r+=2;
		printf("\n");
	}
}

