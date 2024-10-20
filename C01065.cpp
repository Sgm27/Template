#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int d[15];
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
int check(int k)
{
	if (k==2 || k==3 || k==5 || k==7) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	long long n;
	scanf("%lld",&n);
	while (n)
	{
		int tmp=n%10;
		n/=10;
		d[tmp]++;
	}
	for (int i=1;i<=9;i++)
		if (check(i) && d[i]) printf("%d %d\n",i,d[i]);
}

