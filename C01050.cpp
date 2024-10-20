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
	char a[150][150];
	int n,m;
	scanf("%d %d",&m,&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=' ';
	for (int i=1;i<=n;i++)
	{
		a[i][1]='*';
		a[i][m]='*';
	}
	for (int i=1;i<=m;i++)
	{
		a[1][i]='*';
		a[n][i]='*';
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%c",a[i][j]);
		printf("\n");
	}
}

