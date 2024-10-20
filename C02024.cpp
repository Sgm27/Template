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
	int n,m;
	scanf("%d %d",&n,&m);
	int cs=64,csc=65+m-1;
	for (int i=1;i<=n;i++)
	{
		if (i<m)
		{
			cs++;
			for (int j=cs;j<=csc;j++) printf("%c",j);
			for (int j=cs-1;j>=65;j--) printf("%c",j);
		}
		else
			for (int j=csc;j>=65;j--) printf("%c",j);
		printf("\n");
	}
}

