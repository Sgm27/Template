#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n,m,a[105][105];
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
	int x=1,y=1;
	for (int i=1;i<=n*m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		a[x][y]=tmp;
		if (y!=m) y++;
		else
		{
			x++;
			y=1;	
		} 
	}
	int h1=1,h2=n,c1=1,c2=m,cnt=0;
	while (1)
	{
		for (int i=c1;i<=c2;i++) 
		{
			printf("%d ",a[h1][i]);
			cnt++;
			if (cnt==n*m) return;
		}
		h1++;
		for (int i=h1;i<=h2;i++) 
		{
			printf("%d ",a[i][c2]);
			cnt++;
			if (cnt==n*m) return;
		}
		c2--;
		for (int i=c2;i>=c1;i--) 
		{
			printf("%d ",a[h2][i]);
			cnt++;
			if (cnt==n*m) return;
		}
		h2--;
		for (int i=h2;i>=h1;i--) 
		{
			printf("%d ",a[i][c1]);
			cnt++;
			if (cnt==n*m) return;
		}
		c1++;
	}
}

int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d %d",&n,&m);
		process();
		printf("\n");
	}
}

