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


int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,sum=0;
		scanf("%d",&n);
		while (n)
		{
			int tmp=n%10;
			sum+=tmp;
			n/=10;
		}
		if (sum%10==0) printf("YES\n");
		else printf("NO\n");
	}
}

