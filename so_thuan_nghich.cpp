#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


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
void tn(int n)
{
	int a[15],nmax=0;
	while (n)
	{
		a[++nmax]=n%10;
		n/=10;
	}
	for (int i=1;i<=nmax;i++)
		if (a[i]!=a[nmax-i+1]) 
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		tn(n);
	}
}

