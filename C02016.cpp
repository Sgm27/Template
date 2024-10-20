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
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		if (i%2==1) 
		{
			int tmp=i,k=1;
			while (tmp--)
			{
				printf("%d",k);
				k+=2;
			}
		}
		else
		{
			int tmp=i,k=2;
			while (tmp--)
			{
				printf("%d",k);
				k+=2;
			}
		}
		printf("\n");
	}
}

