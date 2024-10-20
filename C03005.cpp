#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
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
	//freopen("thu.inp","r",stdin);
	int a,b;
	scanf("%d %d",&a,&b);
	for (int i=a;i<=b-1;i++)
		for (int j=i+1;j<=b;j++) 
			if (gcd(i,j)==1) printf("(%d,%d)\n",i,j);
}

