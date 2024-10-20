#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,a[15][15],tmp[15][15];

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
void swap(int x,int y)
{
	for (int i=1;i<=x;i++)
		for (int j=1;j<=y;j++) a[i][j]=1-a[i][j];
}
void process()
{
	// bien doi ve 0
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) tmp[i][j]=a[i][j];
	int step=0,min_step=1e7;
	int hang=n,cot=n;
	while (hang && cot)
	{
		for (int i=cot;i>=1;i--) 
			if (a[hang][i]==1) 
			{
				swap(hang,i);
				step++;
			}
		for (int i=hang;i>=1;i--)
			if (a[i][cot]==1)
			{
				swap(i,cot);
				step++;
			}
		hang--;
		cot--;
	}
	min_step=min(min_step,step);
	// bien doi ve 1
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=tmp[i][j];
	step=0;
	hang=n; cot=n;
	while (hang && cot)
	{
		for (int i=cot;i>=1;i--) 
			if (a[hang][i]==0) 
			{
				swap(hang,i);
				step++;
			}
		for (int i=hang;i>=1;i--)
			if (a[i][cot]==0)
			{
				swap(i,cot);
				step++;
			}
		hang--;
		cot--;
	}
	min_step=min(min_step,step+1);
	printf("%d",min_step);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	scanf("%d",&n);
	getchar();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) 
		{
			scanf("%c ",&a[i][j]);
			a[i][j]-='0';
		}
	}
	process();
}

