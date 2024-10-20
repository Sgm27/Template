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
int process(int n, int p)
{
	int tmp=p,cnt=0;
	while (tmp<=n)
	{
		cnt+=(int)(n/tmp);
		tmp*=p;
	}
	return cnt;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n,p;
		scanf("%d %d",&n,&p);
		printf("%d\n",process(n,p));
	}
}

