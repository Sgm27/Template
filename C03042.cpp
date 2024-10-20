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
int check(int n)
{
	int a[105],nmax=0;
	while (n)
	{
		a[++nmax]=n%10;
		n/=10;
	}
	for (int i=1;i<nmax;i++)
		if (a[i]>=a[i+1]) return 0;
	return 1;
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int a,b,cnt=0;
		scanf("%d %d",&a,&b);
		for (int i=a;i<=b;i++)
			if (check(i)) cnt++;
		printf("%d\n",cnt);
	}
}

