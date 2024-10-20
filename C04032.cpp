#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct mang{
	int val,cnt;
};
struct mang a[100005];
int n=0,x[100005],m=0,dem=1;
int check(int n)
{
	int x=10;
	while (n)
	{
		int tmp=n%10;
		n/=10;
		if (tmp>x) return 0;
		x=tmp;
	}
	return 1;
}
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
int cmp1(const void *a,const void *b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tmp;
	while (scanf("%d",&tmp)!=-1)
	{
		if (check(tmp)) x[++n]=tmp;
	}
	qsort(x+1,n,sizeof(int),cmp1);
	
	for (int i=1;i<=n;i++) 
	{
		if (x[i]!=x[i+1])
		{
			m++;
			a[m].val=x[i];
			a[m].cnt=dem;
			dem=1;
		}
		else dem++;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (a[i].cnt>a[j].cnt)
			{
				struct mang tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
	for (int i=1;i<=m;i++) printf("%d %d\n",a[i].val,a[i].cnt);
}

