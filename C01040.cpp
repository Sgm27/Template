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
	int n,sum=0;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		if (n%i==0) sum+=i;
	if (sum==n) printf("1");
	else printf("0");
}
