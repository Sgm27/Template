#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gt[15],a[15][15];
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
void init()
{
	memset(a,0,sizeof(a));
	gt[0]=1;
	for (int i=1;i<=10;i++) gt[i]=gt[i-1]*i;
}
int pascal(int i,int j)
{
	return (gt[i]/(gt[j]*gt[i-j]));
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i>=j) a[i][j]=pascal(i,j);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) 
			if (a[i][j]!=0) printf("%d ",a[i][j]);
		printf("\n");
	}
}

