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
void process(int n)
{
	int res[90005],nmax=0;
	while (n)
	{
		int tmp=n%2;
		res[++nmax]=tmp;
		n/=2;
	}
	for (int i=nmax;i>=1;i--) printf("%d",res[i]);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int n;
	scanf("%d",&n);
	if (!n) 
	{
		printf("0");
		return 0;
	}
	process(n);
}

