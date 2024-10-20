#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n,a[1005];
int gcd(int a,int b)
{
	if (!b) return a;
	else return gcd(b,a%b);
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
void process()
{
	a[0]=1,a[n+1]=1;
	for (int i=0;i<=n;i++) 
		printf("%d ",a[i]*a[i+1]/gcd(a[i],a[i+1]));
	printf("\n");
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		process();
	}
}

