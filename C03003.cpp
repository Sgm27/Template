#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n;
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
int nto(int k)
{
	if (k==2 || k==3) return 1;
	if (k<2 || k%2==0 || k%3==0) return 0;
	int i=5;
	while (i<=(int)(sqrt(k)))
	{
		if (k%i==0 || k%(i+2)==0) return 0;
		else i+=6;
	}
	return 1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	scanf("%d",&n);
	int i=1;
	while (n)
	{
		i++;
		if (nto(i)) 
		{
			printf("%d\n",i);
			n--;
		}
	}
}

