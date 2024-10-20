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
	for (int stt=1;stt<=tc;stt++)
	{
		printf("Test %d:\n",stt);
		int n,m,a[15][15];
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		for (int i=2;i<=n;i++)
		{
			for (int j=2;j<=m;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
}

