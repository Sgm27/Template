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
	int l=1,r=n;
	for (int i=1;i<=n;i++)
	{
		if (i<n)
		{
			for (int j=l;j>1;j--) printf("%d",j);
			for (int j=1;j<=r;j++) printf("%d",j);
			l++;
			r--;
		}
		else
			for (int j=i;j>=i-n+1;j--) printf("%d",j);
		printf("\n");
	}
}


