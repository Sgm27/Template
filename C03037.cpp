#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int nto(int k)
{
	if (k==2 || k==3 || k==5 || k==7) return 1;
	return 0;
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
void process(long long n)
{
	int a[100],nmax=0,d[25];
	memset(d,0,sizeof(d));
	while (n)
	{
		a[++nmax]=n%10;
		n/=10;
	}
	for (int i=1;i<=nmax;i++) 
		if (nto(a[i])) d[a[i]]++;
	for (int i=nmax;i>=1;i--)
		if (d[a[i]])
		{
			printf("%d %d\n",a[i],d[a[i]]);
			d[a[i]]=0;
		}
}

int main()
{
//	freopen("thu.inp","r",stdin);
	long long n;
	scanf("%lld",&n);
	process(n);
}

