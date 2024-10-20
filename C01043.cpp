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
int gt(int k)
{
	int res=1;
	for (int i=1;i<=k;i++) res*=i;
	return res;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int n,sum=0;
	scanf("%d",&n);
	int k=n;
	while (k)
	{
		int tmp=k%10;
		sum+=gt(tmp);
		k/=10;
	}
	if (n==sum) printf("1");
	else printf("0");
}

