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
	int n,m;
	scanf("%d %d",&n,&m);
	int l=m,r=1;
	for (int i=n;i>=1;i--)
	{
		if (i>m)
			for (int j=i;j>=i-m+1;j--) printf("%d",j);
		else
		{
			for (int j=l;j>=1;j--) printf("%d",j);
			for (int j=2;j<=r;j++) printf("%d",j);
			l--;
			r++;
		}
		printf("\n");
	}
}

