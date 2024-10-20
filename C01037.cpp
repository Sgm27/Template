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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main()
{
	//freopen("thu.inp","r",stdin);
	int l,r;
	scanf("%d %d",&l,&r);
	if (l>=r) swap(&l,&r);
	long long res=((l+r)*(r-l+1))/2;
	printf("%lld",res);
}

