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


int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,x;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&x);
			if (x%2==0) printf("%d ",x);
		}
		printf("\n");
	}
}

