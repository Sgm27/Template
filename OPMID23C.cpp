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
void process(int n,int s,int m)
{
	if (n<=m || n*6<m*7) 
	{
		printf("-1\n");
		return;
	}
	int tmp=s*m,x;
	if (tmp%n==0) x=tmp/n;
	else x=tmp/n +1;
	printf("%d\n",x);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,s,m;
		scanf("%d %d %d",&n,&s,&m);
		process(n,s,m);
	}
}

