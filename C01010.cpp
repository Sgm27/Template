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
	int n,ngay,tuan,nam;
	scanf("%d",&n);
	nam=(int)(n/365);
	n-=nam*365;
	tuan=(int)(n/7);
	n-=tuan*7;
	printf("%d %d %d",nam,tuan,n);
}


