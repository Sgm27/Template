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
int cp(int k)
{
	int tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
int hoanhao(int n)
{
	if (n==1) return 0;
	int sum=1;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0)
		{
			sum+=i;
			sum+=n/i;
		}
	if (cp(n)) sum-=sqrt(n);
	if (sum==n) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=min(n,m);i<=max(n,m);i++) 
		if (hoanhao(i)) printf("%d ",i);
}
