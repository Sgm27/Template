#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
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
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int cs=0;
		for (int j=1;j<=i;j++) printf("0 ");
		for (int j=i+1;j<=n;j++) printf("%d ",++cs);
		printf("\n");
	}
}

