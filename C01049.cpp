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
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,dl=0,dc=0;
		scanf("%d",&n);
		while (n)
		{
			int tmp=n%10;
			if (tmp%2) dl++;
			else dc++;
			n/=10;
		}
		printf("%d %d\n",dl,dc);
	}
}

