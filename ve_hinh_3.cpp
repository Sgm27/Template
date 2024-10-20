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
	int l=n-1,r=n-1;
	for (int i=1;i<=n;i++)
	{
		if (i==n) 
		{
			for (int j=1;j<=n;j++) printf("* ");
			return 0;
		}
		for (int j=1;j<=l;j++) printf(" ");
		if (l==r) printf("*");
		else
		{
			printf("*");
			for (int j=l+1;j<=r-1;j++) printf(" ");
			printf("*");
		}
		l--;
		r++;
		printf("\n");
	}
}

