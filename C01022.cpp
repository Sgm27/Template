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
	int tc,n,sum;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		sum=0;
		while (n)
		{
			int tmp=n%10;
			n/=10;
			sum+=tmp;
		}
		printf("%d\n",sum);
	}
}

