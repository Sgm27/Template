#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int da[1005],db[1005],a[105],b[105];

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
int cmp(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	memset(da,0,sizeof(da));
	memset(db,0,sizeof(db));
	int n,m,x,nmax=0,mmax=0;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (da[x]==0) a[++nmax]=x;
		da[x]=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if (db[x]==0) b[++mmax]=x;
		db[x]=1;
	}
	qsort(a+1,nmax,sizeof(int),cmp);
	qsort(b+1,mmax,sizeof(int),cmp);
	for (int i=1;i<=nmax;i++) 
		if (db[a[i]]) printf("%d ",a[i]);
	printf("\n");
	for (int i=1;i<=nmax;i++)
		if (db[a[i]]==0) printf("%d ",a[i]);
	printf("\n");
	for (int i=1;i<=mmax;i++)
		if (da[b[i]]==0) printf("%d ",b[i]);
}

