#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n,k,d[500005],a[500005],nmax=0;
int cmp(const void *a,const void *b)
{
	int *x=(int *)a;
	int *y=(int *)b;
	return *x-*y;
}
void input()
{
	memset(d,0,sizeof(d));
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (!d[x])
		{
			d[x]++;
			a[++nmax]=x;
		}
	}
	qsort(a+1,nmax,sizeof(a[1]),cmp);
	int check=1;
	for (int i=1;i<=n-1;i++)
	{
		if (a[i]>=k) 
		{
			printf("%d",i);
			return;
		}
	}
	printf("%d",nmax+1);
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


int main()
{
//	freopen("thu.inp","r",stdin);
	input();
}

