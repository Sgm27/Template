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
	int a,b,c,Max,Min;
	scanf("%d %d %d",&a,&b,&c);
	Max=(a+b+abs(a-b))/2;
	Min=(a+b-abs(a-b))/2;
	Max=(Max+c+abs(Max-c))/2;
	Min=(Min+c-abs(Min-c))/2;
	printf("%d %d",Max,Min);
}

