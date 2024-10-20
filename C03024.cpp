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
int tong_cs(int k)
{
	int sum=0;
	while (k)
	{
		int tmp=k%10;
		k/=10;
		sum+=tmp;
	}
	return sum;
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
	int a,b;
	scanf("%d %d",&a,&b);
	if (tong_cs(a)>tong_cs(b)) swap(&a,&b);
	printf("%d %d",a,b);
}

