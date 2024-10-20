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
	int n;
	scanf("%d",&n);
	if (n<=50)
		printf("%d",n*600);
	else 
	if (n<=150)
		printf("%d",600*50+(n-50)*400);
	else
		printf("%d",600*50+100*400+(n-150)*200);
}

