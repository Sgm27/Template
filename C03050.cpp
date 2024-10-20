#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[100005];

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
	memset(d,0,sizeof(d));
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		d[x]++;
		d[y]++;
		if (x==y) d[x]--;
	}
	for (int i=1;i<=n;i++)
		if (d[i]==n-1) 
		{
			printf("Yes");
			return 0;
		}
	printf("No");
}
