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
int process(int n, int p,int x)
{
	int tmp=p,cnt=0;
	while (tmp<=n)
	{
		cnt+=(int)(n/tmp);
		tmp*=p;
	}
	if (cnt>=x) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int n,p,x;
	scanf("%d %d",&n,&x);
	p=2;
	if (process(n,p,x)) printf("Yes");
	else printf("No");
}


