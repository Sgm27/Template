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
	int n,m,Max,Min;
	scanf("%d %d",&n,&m);
	Max=max(n,m);
	Min=min(n,m);
	for (int i=1;i<=n;i++)
	{
		if (i<=Min)
		{
			int cs=Max+96;
			for (int j=cs;j>=cs-i+1;j--) printf("%c",j);
			cs=cs-i+1;
			int tmp=m-i;
			while (tmp--) printf("%c",cs);
		}
		else
		{
			int tmp=m,cs=Max+96;
			while (tmp--)
			{
				printf("%c",cs--);
			}
		}
		printf("\n");
	}
}

