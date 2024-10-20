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
int check(int n)
{
	int a[105],nmax=0,sum=0;
	while (n)
	{
		a[++nmax]=n%10;
		if (a[nmax]==4) return 0;
		sum+=a[nmax];
		n/=10;
	}
	if (sum%10!=0) return 0;
	for (int i=1;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}
void process(int n)
{
	int l=1,r;
	for (int i=1;i<n;i++) l*=10;
	r=l*10-1;
	for (int i=l;i<=r;i++) 
		if (check(i)) printf("%d ",i);
	printf("\n");
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		process(n);
	}
}

