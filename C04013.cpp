#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[1000005];

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
	memset(d,0,sizeof(d));
	int n,a[1005],res[1005],nmax=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		d[a[i]]++;
	} 
	for (int i=1;i<=n;i++)
		if (d[a[i]]==1) 
		{
			res[++nmax]=a[i];
			d[a[i]]=0;
		}
	printf("%d\n",nmax);
	for (int i=1;i<=nmax;i++)
		printf("%d ",res[i]);
}

