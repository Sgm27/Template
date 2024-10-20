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
int check(long long n)
{
	int a[105],nmax=0,sum=0;
	while (n)
	{
		int tmp=n%10;
		a[++nmax]=tmp;
		sum+=tmp;
		if (tmp%2==0) return 0; 
		n/=10;
	}
	if (sum%2==0) return 0;
	for (int i=1;i<=nmax/2;i++)
		if (a[i]!=a[nmax-i+1]) return 0;
	return 1;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		long long n;
		scanf("%lld",&n);
		if (check(n)) printf("YES\n");
		else printf("NO\n");
	}
}

