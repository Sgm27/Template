#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int x[25];

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
void in(int n)
{
	for (int i=1;i<=n;i++) printf("%d",x[i]);
	printf(" ");
}
void Try(int i,int n)
{
	for (int j=x[i-1];j<=9;j++)
	{
		x[i]=j;
		if (i==n) in(n);
		else Try(i+1,n);
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		x[0]=1;
		Try(1,n);
		printf("\n");
	}
}

