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
	int cs=64,csc=64+m-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=cs;j<=cs+m-1;j++) 
			printf("%c",min(j,csc));
		printf("\n");
		cs++;
	}
}

