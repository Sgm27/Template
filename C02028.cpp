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
	int n,r=65;
	scanf("%d",&n);
	int cs=n;
	for (int i=1;i<=n;i++)
	{
		int tmp=r;
		for (int j=1;j<=cs;j++) 
		{
			printf("%c",tmp);
			tmp+=2;
		}
		r+=2;
		cs--;
		printf("\n");
	}
}

