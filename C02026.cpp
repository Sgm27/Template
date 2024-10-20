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
	int csd=64+n,csc=64+m;
	for (int i=1;i<=n;i++)
	{
		if (csd>=csc) 
		{
			for (int j=1;j<=m;j++) printf("%c",csc);
			csd--;
		}
		else
		{
			for (int j=csd;j<=csd+m-1;j++) 
				printf("%c",min(j,csc));
			csd--;
		}
		printf("\n");
	}
}

