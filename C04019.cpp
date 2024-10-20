#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int d[30005],a[105],Max;

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
		memset(d,0,sizeof(d));
		int n,Max=-1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			d[a[i]]++;
			Max=max(Max,d[a[i]]);
		}
		for (int i=1;i<=n;i++)
			if (d[a[i]]==Max) 
			{
				printf("%d ",a[i]);
				d[a[i]]=0;
			}
		printf("\n");
	}
}

