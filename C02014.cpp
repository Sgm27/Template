#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int d[15];
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
	int n,x;
	scanf("%d",&x);
	n=2*x-1;
	for (int i=0;i<x;i++)
	{
		for (int i=1;i<=15;i++) d[i]=0;
		int l=1,r=n;
		int tmp=x-i;
		for (int j=x;j>=tmp;j--)
		{
			d[l++]=j;
			d[r--]=j;
		}
		for (int j=l;j<=r;j++) d[j]=tmp;
		for (int j=1;j<=n;j++) printf("%d",d[j]);
		printf("\n");
	}
	for (int i=2;i<=x;i++)
	{
		for (int i=1;i<=15;i++) d[i]=0;
		int l=1,r=n;
		for (int j=x;j>=i;j--) 
		{
			d[l++]=j;
			d[r--]=j;
		}
		for (int j=l;j<=r;j++) d[j]=i;
		for (int j=1;j<=n;j++) printf("%d",d[j]);
		printf("\n");
	}
}

